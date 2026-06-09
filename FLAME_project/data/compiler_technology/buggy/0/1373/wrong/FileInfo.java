import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.regex.Pattern;

public class FileInfo {

    private static final Pattern IDENTIFIER_PATTERN = Pattern.compile("^[a-zA-Z_][a-zA-Z0-9_]*$");
    private static final Pattern NUMBER_PATTERN = Pattern.compile("^[0-9]+$");
    private static final Pattern STRING_PATTERN = Pattern.compile("^\".*\"$");
    private static final Pattern CHAR_PATTERN = Pattern.compile("^'[^']'$");

    public ArrayList<Token> read() {
        ArrayList<Token> info = new ArrayList<>();
        String filepath = "testfile.txt";
        File file = new File(filepath);
        if (!file.exists()){
            System.out.println("对不起，不包含指定路径的文件");
        } else {

            try (PushbackReader reader = new PushbackReader(new FileReader(file))) {
                //读取文件内容
                StringBuilder currentToken = new StringBuilder();
                int currentChar;
                boolean isComment1 = false;
                boolean isComment2 = false;
                int line = 1;

                while ((currentChar = reader.read()) != -1) {

                    char c = (char) currentChar;

                    if (isComment1 || isComment2) {
                        // 处理注释结束
                        if (isComment1) { // "//"情况
                            if (c == '\n') {
                                isComment1 = false;
                                line++;
                                continue;
                            }
                        } else if (isComment2) { // "/*"情况
                            if (c == '*') {
                                int nextChar = reader.read();
                                if ((char) nextChar == '/') {
                                    isComment2 = false;
                                    continue;
                                } else {
                                    reader.unread(nextChar);
                                }
                            }
                        }
                        continue;
                    }

                    // 忽略空白字符
                    if (Character.isWhitespace(c)) {
                        if (!currentToken.isEmpty()) {
                            addToken(info, currentToken.toString(), line);
                            currentToken.setLength(0);
                        }
                        if (c == '\n') {
                            line++;
                        }
                        continue;
                    }

                    // 处理注释
                    if (c == '/') {
                        int nextChar = reader.read();
                        if ((char) nextChar == '/') {
                            isComment1 = true;
                            continue;
                        } else if ((char) nextChar == '*') {
                            isComment2 = true;
                            continue;
                        } else {
                            reader.unread(nextChar);
                        }
                    }
                    // 处理字符串
                    if (c == '"') {
                        if (!currentToken.isEmpty()) {
                            addToken(info, currentToken.toString(), line);
                            currentToken.setLength(0);
                        }
                        int strChar;
                        StringBuilder strBuilder = new StringBuilder();
                        strBuilder.append('"');
                        do {
                            strChar = reader.read();
                            strBuilder.append((char) strChar);
                        } while ((char) strChar != '"');
                        addToken(info, String.valueOf(strBuilder), line);
                        strBuilder.setLength(0);
                        continue;
                    }

                    //处理字符常量
                    if (c == '\'') {
                        int nextChar = reader.read();
                        int uselessChar = reader.read(); // '''
                        StringBuilder strBuilder = new StringBuilder();
                        strBuilder.append("'");
                        strBuilder.append((char)nextChar);
                        strBuilder.append("'");
                        addToken(info, String.valueOf(strBuilder), line);
                        strBuilder.setLength(0);
                        continue;
                    }

                    // 处理多字符运算符
                    if (isOperator(c)) {
                        if (!currentToken.isEmpty()) {
                            addToken(info, currentToken.toString(), line);
                            currentToken.setLength(0);
                        }
                        currentToken.append(c);
                        int nextChar = reader.read();
                        if (isNextCharOperator(c, (char) nextChar)) { // 检查下一个字符是否也是运算符
                            currentToken.append((char) nextChar);
                        } else {
                            reader.unread(nextChar);
                        }
                        addToken(info, currentToken.toString(), line);
                        currentToken.setLength(0);
                        continue;
                    }

                    // 处理单个字符（如分隔符）
                    if (isSeparator(c)) {
                        if (!currentToken.isEmpty()) {
                            addToken(info, currentToken.toString(), line);
                            currentToken.setLength(0);
                        }
                        addToken(info, String.valueOf(c), line);
                        continue;
                    }

                    currentToken.append(c);
                }

                // 处理最后一个记号
                if (currentToken.length() > 0) {
                    addToken(info, currentToken.toString(), line);
                }
                //处理结束
                reader.close();

            } catch (IOException e) {
                e.printStackTrace();
            }

        }
        return info;
    }

    private boolean isOperator(char c) {
        return c == '&' || c == '|' || c == '!' || c == '<' || c == '>' || c == '=';
    }

    private boolean isNextCharOperator(char c1, char c2) {
        if (c1 == '&' && c2 == '&') {
            return true;
        } else if (c1 == '|' && c2 == '|') {
            return true;
        } else if (c1 == '<' && c2 == '=') {
            return true;
        } else if (c1 == '>' && c2 == '=') {
            return true;
        } else if (c1 == '=' && c2 == '=') {
            return true;
        } else if (c1 == '!' && c2 == '=') {
            return true;
        }
        return false;
    }

    private boolean isSeparator(char c) {
        if (c == '!' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
        || c == '<' || c == '>' || c == '=' || c == ';' || c == ',' || c == '('
        || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ) {
            return true;
        }
        return false;
    }

    private void addToken(ArrayList<Token> info, String tokenValue, int line) {
        TokenType type = identifyTokenType(tokenValue);
        if (type.toString().equals("UNKNOWN")) {
            info.add(new Token(type, String.valueOf(line)));
        } else {
            info.add(new Token(type, tokenValue));
        }
    }

    private TokenType identifyTokenType(String value) {
        if (NUMBER_PATTERN.matcher(value).matches()) return TokenType.INTCON;
        if (STRING_PATTERN.matcher(value).matches()) return TokenType.STRCON;
        if (CHAR_PATTERN.matcher(value).matches()) return TokenType.CHRCON;
        return switch (value) {
            case "main" -> TokenType.MAINTK;
            case "else" -> TokenType.ELSETK;
            case "void" -> TokenType.VOIDTK;
            case "const" -> TokenType.CONSTTK;
            case "int" -> TokenType.INTTK;
            case "char" -> TokenType.CHARTK;
            case "break" -> TokenType.BREAKTK;
            case "continue" -> TokenType.CONTINUETK;
            case "if" -> TokenType.IFTK;
            case "for" -> TokenType.FORTK;
            case "return" -> TokenType.RETURNTK;
            case "getint" -> TokenType.GETINTTK;
            case "getchar" -> TokenType.GETCHARTK;
            case "printf" -> TokenType.PRINTFTK;
            case "!" -> TokenType.NOT;
            case "*" -> TokenType.MULT;
            case "&&" -> TokenType.AND;
            case "||" -> TokenType.OR;
            case "/" -> TokenType.DIV;
            case "%" -> TokenType.MOD;
            case "+" -> TokenType.PLUS;
            case "-" -> TokenType.MINU;
            case "<" -> TokenType.LSS;
            case "<=" -> TokenType.LEQ;
            case ">" -> TokenType.GRE;
            case ">=" -> TokenType.GEQ;
            case "==" -> TokenType.EQL;
            case "!=" -> TokenType.NEQ;
            case "=" -> TokenType.ASSIGN;
            case ";" -> TokenType.SEMICN;
            case "," -> TokenType.COMMA;
            case "(" -> TokenType.LPARENT;
            case ")" -> TokenType.RPARENT;
            case "{" -> TokenType.LBRACE;
            case "}" -> TokenType.RBRACE;
            case "[" -> TokenType.LBRACK;
            case "]" -> TokenType.RBRACK;
            case "&" -> TokenType.UNKNOWN; // 或其他默认处理包括'&','|'
            case "|" -> TokenType.UNKNOWN;
            default -> TokenType.IDENFR;
        };
    }
}
