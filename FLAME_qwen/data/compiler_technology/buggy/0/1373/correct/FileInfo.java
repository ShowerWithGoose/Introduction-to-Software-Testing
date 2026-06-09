import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.regex.Pattern;

public class FileInfo {

    private static final Pattern NUMBER_PATTERN = Pattern.compile("^[0-9]+$");
    private static final Pattern STRING_PATTERN = Pattern.compile("^\".*\"$");

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
                        if (currentToken.length() != 0) {
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
                        if (currentToken.length() != 0) {
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
                        int next2Char = reader.read();
                        StringBuilder strBuilder = new StringBuilder();
                        if ((char) nextChar == '\\') { //有转义符
                            int next3Char = reader.read();
                            strBuilder.append("'");
                            strBuilder.append((char)nextChar);
                            strBuilder.append((char)next2Char);
                            strBuilder.append("'");
                        } else { //没有转义符
                            strBuilder.append("'");
                            strBuilder.append((char)nextChar);
                            strBuilder.append("'");
                        }
                        addToken(info, String.valueOf(strBuilder), line);
                        strBuilder.setLength(0);
                        continue;
                    }

                    // 处理多字符运算符
                    if (isOperator(c)) {
                        if (currentToken.length() != 0) {
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
                        if (currentToken.length() != 0) {
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
        if (value.charAt(0) == '\'') return TokenType.CHRCON;
        if ("main".equals(value)) {
            return TokenType.MAINTK;
        } else if ("else".equals(value)) {
            return TokenType.ELSETK;
        } else if ("void".equals(value)) {
            return TokenType.VOIDTK;
        } else if ("const".equals(value)) {
            return TokenType.CONSTTK;
        } else if ("int".equals(value)) {
            return TokenType.INTTK;
        } else if ("char".equals(value)) {
            return TokenType.CHARTK;
        } else if ("break".equals(value)) {
            return TokenType.BREAKTK;
        } else if ("continue".equals(value)) {
            return TokenType.CONTINUETK;
        } else if ("if".equals(value)) {
            return TokenType.IFTK;
        } else if ("for".equals(value)) {
            return TokenType.FORTK;
        } else if ("return".equals(value)) {
            return TokenType.RETURNTK;
        } else if ("getint".equals(value)) {
            return TokenType.GETINTTK;
        } else if ("getchar".equals(value)) {
            return TokenType.GETCHARTK;
        } else if ("printf".equals(value)) {
            return TokenType.PRINTFTK;
        } else if ("!".equals(value)) {
            return TokenType.NOT;
        } else if ("*".equals(value)) {
            return TokenType.MULT;
        } else if ("&&".equals(value)) {
            return TokenType.AND;
        } else if ("||".equals(value)) {
            return TokenType.OR;
        } else if ("/".equals(value)) {
            return TokenType.DIV;
        } else if ("%".equals(value)) {
            return TokenType.MOD;
        } else if ("+".equals(value)) {
            return TokenType.PLUS;
        } else if ("-".equals(value)) {
            return TokenType.MINU;
        } else if ("<".equals(value)) {
            return TokenType.LSS;
        } else if ("<=".equals(value)) {
            return TokenType.LEQ;
        } else if (">".equals(value)) {
            return TokenType.GRE;
        } else if (">=".equals(value)) {
            return TokenType.GEQ;
        } else if ("==".equals(value)) {
            return TokenType.EQL;
        } else if ("!=".equals(value)) {
            return TokenType.NEQ;
        } else if ("=".equals(value)) {
            return TokenType.ASSIGN;
        } else if (";".equals(value)) {
            return TokenType.SEMICN;
        } else if (",".equals(value)) {
            return TokenType.COMMA;
        } else if ("(".equals(value)) {
            return TokenType.LPARENT;
        } else if (")".equals(value)) {
            return TokenType.RPARENT;
        } else if ("{".equals(value)) {
            return TokenType.LBRACE;
        } else if ("}".equals(value)) {
            return TokenType.RBRACE;
        } else if ("[".equals(value)) {
            return TokenType.LBRACK;
        } else if ("]".equals(value)) {
            return TokenType.RBRACK;
        } else if ("&".equals(value)) {
            return TokenType.UNKNOWN;
        } else if ("|".equals(value)) {
            return TokenType.UNKNOWN;
        } else {
            return TokenType.IDENFR;
        }

    }
}
