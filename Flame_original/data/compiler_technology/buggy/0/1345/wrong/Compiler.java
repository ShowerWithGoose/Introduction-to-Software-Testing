import java.io.*;
import java.util.*;

public class Compiler {
    private static final Set<String> KEYWORDS = new HashSet<>(Arrays.asList(
            "const", "int", "char", "void", "main", "if", "else", "for", "break", "continue", "return", "getint", "getchar", "printf"));
    private static final Set<String> SYMBOLS = new HashSet<>(Arrays.asList(
            "+", "-", "*", "/", "%", "=", "==", "!=", "<", "<=", ">", ">=", "&&", "||", "(", ")", "[", "]", "{", "}", ";", ",","!","&","|"));
    private static final Set<Character> WHITESPACES = new HashSet<>(Arrays.asList(' ', '\t', '\r', '\n'));
    private static int lineNumber = 1;
    private static int zhushi = 0;
    private static BufferedWriter lexerWriter;
    private static BufferedWriter errorWriter;
    private static void writeLexerOutput(String tokenType, String value) throws IOException {
        lexerWriter.write(tokenType + " " + value);
        lexerWriter.newLine();
    }

    private static void writeError(String errorType) throws IOException {
        errorWriter.write(lineNumber + " " + errorType);
        errorWriter.newLine();
    }

    private static String mapSymbol(String symbol) {
        switch (symbol) {
            case "+":
                return "PLUS";
            case "-":
                return "MINU";
            case "*":
                return "MULT";
            case "/":
                return "DIV";
            case "%":
                return "MOD";
            case "=":
                return "ASSIGN";
            case "!":
                return "NOT";
            case "==":
                return "EQL";
            case "!=":
                return "NEQ";
            case "<":
                return "LSS";
            case "<=":
                return "LEQ";
            case ">":
                return "GRE";
            case ">=":
                return "GEQ";
            case "&&":
                return "AND";
            case "||":
                return "OR";
            case "(":
                return "LPARENT";
            case ")":
                return "RPARENT";
            case "[":
                return "LBRACK";
            case "]":
                return "RBRACK";
            case "{":
                return "LBRACE";
            case "}":
                return "RBRACE";
            case ";":
                return "SEMICN";
            case ",":
                return "COMMA";
            default:
                return "UNKNOWN";
        }
    }
    private static void analyzeLine(String line) throws IOException {
        int length = line.length();
        int i = 0;

        while (i < length) {
            char c = line.charAt(i);
            if(zhushi == 1){
                while (i < length) {
                    if (line.charAt(i) == '*' && i + 1 < length && line.charAt(i + 1) == '/') {
                        i += 2; // 跳过 '*/'
                        if(zhushi == 1){
                            zhushi = 0;
                        }
                        break;
                    }
                    i++;
                }
                continue;
            }
            // 跳过空白字符
            if (WHITESPACES.contains(c)) {
                if (c == '\n') {
                }
                i++;
                continue;
            }
            if (c == '/') {
                if (i + 1 < length && line.charAt(i + 1) == '/') {
                    // 跳过注释内容
                    while (i < length && line.charAt(i) != '\n') {
                        i++;
                    }
                    continue;
                } else if (i + 1 < length && line.charAt(i + 1) == '*') {
                        i += 2; // 跳过 '/*'
                        if(zhushi == 0){
                            zhushi = 1;
                        }
                        while (i < length) {
                            if (line.charAt(i) == '*' && i + 1 < length && line.charAt(i + 1) == '/') {
                                i += 2; // 跳过 '*/'
                                if(zhushi == 1){
                                    zhushi = 0;
                                }
                                break;
                            }
                            i++;
                        }
                        continue;
                }
            }
            // 识别标识符和关键字
            if (Character.isLetter(c) || c == '_') {
                StringBuilder identifier = new StringBuilder();
                while (i < length && (Character.isLetterOrDigit(line.charAt(i)) || line.charAt(i) == '_')) {
                    identifier.append(line.charAt(i));
                    i++;
                }
                String token = identifier.toString();
                if (KEYWORDS.contains(token)) {
                    writeLexerOutput(token.toUpperCase() + "TK", token);
                } else {
                    writeLexerOutput("IDENFR", token);
                }
            }
            // 识别数字
            else if (Character.isDigit(c)) {
                StringBuilder number = new StringBuilder();
                while (i < length && Character.isDigit(line.charAt(i))) {
                    number.append(line.charAt(i));
                    i++;
                }
                writeLexerOutput("INTCON", number.toString());
            }
            // 识别字符串常量
            else if (c == '"') {
                i++;
                StringBuilder strConst = new StringBuilder("\"");
                while (i < length && (line.charAt(i) != '"' || (i>0 && line.charAt(i-1) =='\\') ) ) {
                    strConst.append(line.charAt(i));
                    i++;
                }
                if (i < length && line.charAt(i) == '"') {
                    strConst.append('"');
                    i++;
                    writeLexerOutput("STRCON", strConst.toString());
                } else {
                    writeError("a");
                }
            }
            // 识别字符常量
            else if (c == '\'') {
                i++;
                StringBuilder charConst = new StringBuilder("'");
                while(i < length && (line.charAt(i) != '\''|| (i>0 && line.charAt(i-1) =='\\') )){
                    charConst.append(line.charAt(i));
                    i++;
                }
                if(i<length && line.charAt(i) == '\''){
                    charConst.append('\'');
                    i++;
                    writeLexerOutput("CHRCON", charConst.toString());
                }
//                if (i < length) {
//                    charConst.append(line.charAt(i));
//                    i++;
//                    if (i < length && (line.charAt(i) == '\''|| (i>0 && line.charAt(i-1) =='\\') )) {
//                        charConst.append('\'');
//                        i++;
//                        writeLexerOutput("CHRCON", charConst.toString());
//                    } else {
//                        writeError("b"); // 处理字符未正确结束的情况
//                    }
//                }
                else {
                    writeError("b"); // 处理字符常量没有内容的情况
                }
            }
            // 识别单字符符号
            else if (SYMBOLS.contains(Character.toString(c))) {
                if (i + 1 < length) {
                    String twoCharSymbol = line.substring(i, i + 2);
                    if (SYMBOLS.contains(twoCharSymbol)) {
                        writeLexerOutput(mapSymbol(twoCharSymbol), twoCharSymbol);
                        i += 2;
                        continue;
                    }
                }
                if (c == '&') {
                    writeLexerOutput(mapSymbol("&&"), Character.toString(c));
                    writeError(Character.toString(c));
                    i++;
                    continue;
                }
                if (c == '|') {
                    writeLexerOutput(mapSymbol("||"), Character.toString(c));
                    writeError(Character.toString(c));
                    i++;
                    continue;
                }
                writeLexerOutput(mapSymbol(Character.toString(c)), Character.toString(c));
                i++;
            }
                // 识别非法字符
            else {
                writeError("a");
                i++;
            }
        }

    }
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
            lexerWriter = new BufferedWriter(new FileWriter("lexer.txt"));
            errorWriter = new BufferedWriter(new FileWriter("error.txt"));

            String line;
            while ((line = reader.readLine()) != null) {
                line = line + "\n";
                analyzeLine(line);
                lineNumber++;
            }

            reader.close();
            lexerWriter.close();
            errorWriter.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}
