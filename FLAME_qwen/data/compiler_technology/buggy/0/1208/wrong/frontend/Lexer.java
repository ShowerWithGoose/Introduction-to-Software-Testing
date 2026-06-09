package frontend;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Map;
import java.util.List;

public class Lexer {
    private final String source; //源程序字符串
    private int curPos = 0; //当前字符串位置指针
    private Token token; //解析单词值
    // private LexType lexType; //解析单词类型
    private final Map<String, LexType> reserveWords = Map.ofEntries(  //保留字表
            Map.entry("const", LexType.CONSTTK),
            Map.entry("int", LexType.INTTK),
            Map.entry("char", LexType.CHARTK),
            Map.entry("void", LexType.VOIDTK),
            Map.entry("main", LexType.MAINTK),
            Map.entry("getint", LexType.GETINTTK),
            Map.entry("getchar", LexType.GETCHARTK),
            Map.entry("printf", LexType.PRINTFTK),
            Map.entry("if", LexType.IFTK),
            Map.entry("else", LexType.ELSETK),
            Map.entry("for", LexType.FORTK),
            Map.entry("break", LexType.BREAKTK),
            Map.entry("continue", LexType.CONTINUETK),
            Map.entry("return", LexType.RETURNTK)
    );
    private int lineNum = 1; //当前行号
    // private int number; //解析数值
    private final int length;
    private final List<Token> tokenList = new ArrayList<>();
    private final List<Error> errorList = new ArrayList<>();

    public Lexer(String source) {
        this.source = source;
        this.length = source.length();
    }

    // 处理下一个单词
    public boolean next() {
        StringBuilder sb = new StringBuilder();
        char c = source.charAt(curPos++);
        if(c == '/') {
            if(curPos < length && source.charAt(curPos) == '/') {
                do {
                    c = source.charAt(curPos++);
                } while (curPos < length && source.charAt(curPos) != '\n');
                if (curPos < length) {
                    c = source.charAt(curPos++);
                    lineNum++;
                }
            } else if (curPos < length && source.charAt(curPos) == '*') {
                c = source.charAt(curPos++);
                while (curPos + 1 < length && source.charAt(curPos) != '*') {
                    c = source.charAt(curPos++);
                    if (c == '\n') {
                        lineNum++;
                    } else if (c == '*' && source.charAt(curPos) == '/') {
                        break;
                    }
                }
            } else {
                sb.append(c);
                token = new Token(LexType.DIV, sb.toString(), lineNum);
                tokenList.add(token);
            }
        } else if (isNonDigit(c)) {
            sb.append(c);
            while (curPos < length && isWord(source.charAt(curPos))) {
                c = source.charAt(curPos++);
                sb.append(c);
            }
            String str = sb.toString();
            token = new Token(reserveWords.getOrDefault(str, LexType.IDENFR), str, lineNum);
            tokenList.add(token);
        } else if (Character.isDigit(c)) {
            sb.append(c);
            if (c != '0') {
                while (curPos < length && Character.isDigit(source.charAt(curPos))) {
                    c = source.charAt(curPos++);
                    sb.append(c);
                }
            }
            token = new Token(LexType.INTCON, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '\'') {
            sb.append(c);
            // 这里除了charconst，还可能有别的情况没？同时在这里假定单引号之间可能不只存在一个字符
            while (curPos < length && source.charAt(curPos) != '\'') {
                c = source.charAt(curPos++);
                if (c == '\\' && curPos + 1 < length) {
                    sb.append(c);
                    c = source.charAt(curPos++);
                }
                sb.append(c);
            }
            if (curPos < length) {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.CHRCON, sb.toString(), lineNum);
                tokenList.add(token);
            }
        } else if (c == '\"') {
            sb.append(c);
            // System.out.println("before while c = " + c);
            // System.out.println("before while source.charAt(curPos) = " + source.charAt(curPos));
            while (curPos < length && source.charAt(curPos) != '\"') {
                c = source.charAt(curPos++);
                if (c == '\\' && curPos + 1 < length) {
                    sb.append(c);
                    c = source.charAt(curPos++);
                    // System.out.println("while c = " + c);
                    // System.out.println("source.charAt(curPos) = " + source.charAt(curPos));
                }
                sb.append(c);
            }
            if (curPos < length) {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.STRCON, sb.toString(), lineNum);
                tokenList.add(token);
            }
        } else if (c == '\n') {
            lineNum++;
        } else if (c == '!') {
            sb.append(c);
            if (source.charAt(curPos) == '=') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.NEQ, sb.toString(), lineNum);
            } else {
                token = new Token(LexType.NOT, sb.toString(), lineNum);
            }
            tokenList.add(token);
        } else if (c == '<') {
            sb.append(c);
            if (source.charAt(curPos) == '=') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.LEQ, sb.toString(), lineNum);
            } else {
                token = new Token(LexType.LSS, sb.toString(), lineNum);
            }
            tokenList.add(token);
        } else if (c == '>') {
            sb.append(c);
            if (source.charAt(curPos) == '=') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.GEQ, sb.toString(), lineNum);
            } else {
                token = new Token(LexType.GRE, sb.toString(), lineNum);
            }
            tokenList.add(token);
        } else if (c == '=') {
            sb.append(c);
            if (source.charAt(curPos) == '=') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.EQL, sb.toString(), lineNum);
            } else {
                token = new Token(LexType.ASSIGN, sb.toString(), lineNum);
            }
            tokenList.add(token);
        } else if (c == '+') {
            sb.append(c);
            token = new Token(LexType.PLUS, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '-') {
            sb.append(c);
            token = new Token(LexType.MINU, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '*') {
            sb.append(c);
            token = new Token(LexType.MULT, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '%') {
            sb.append(c);
            token = new Token(LexType.MOD, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == ';') {
            sb.append(c);
            token = new Token(LexType.SEMICN, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == ',') {
            sb.append(c);
            token = new Token(LexType.COMMA, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '(') {
            sb.append(c);
            token = new Token(LexType.LPARENT, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == ')') {
            sb.append(c);
            token = new Token(LexType.RPARENT, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '[') {
            sb.append(c);
            token = new Token(LexType.LBRACK, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == ']') {
            sb.append(c);
            token = new Token(LexType.RBRACK, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '{') {
            sb.append(c);
            token = new Token(LexType.LBRACE, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '}') {
            sb.append(c);
            token = new Token(LexType.RBRACE, sb.toString(), lineNum);
            tokenList.add(token);
        } else if (c == '&') {
            sb.append(c);
            if (source.charAt(curPos) == '&') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.AND, sb.toString(), lineNum);
                tokenList.add(token);
            } else {
                Error error = new Error(lineNum, 'a');
                errorList.add(error);
            }
        } else if (c == '|') {
            sb.append(c);
            if (source.charAt(curPos) == '|') {
                c = source.charAt(curPos++);
                sb.append(c);
                token = new Token(LexType.OR, sb.toString(), lineNum);
                tokenList.add(token);
            } else {
                Error error = new Error(lineNum, 'a');
                errorList.add(error);
            }
        }
        return curPos < length;
    }

    // 获得读取的单词值
    public String getContent() {
        return token.getContent();
    }

    // 获得读取的单词类型
    public LexType getLexType() {
        return token.getType();
    }

    private boolean isNonDigit(char c) {
        return (c == '_') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    private boolean isWord(char c) {
        return isNonDigit(c) || (c >= '0' && c <= '9');
    }

    private boolean isNonZeroDigit(char c) {
        return (c >= '1' && c <= '9');
    }

    public void output() {
        if (errorList.isEmpty()) {
            File file = new File("lexer.txt");
            try {
                if (!file.exists()) {
                    Files.createFile(file.toPath());
                }
                try (FileOutputStream fos = new FileOutputStream(file, true)) {
                    for (Token t : tokenList) {
                        String str = t.getType().toString() + ' ' + t.getContent() + '\n';
                        fos.write(str.getBytes());
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
                throw new RuntimeException("Error while writing tokens to file", e);
            }
        } else {
            File file = new File("error.txt");
            try {
                if (!file.exists()) {
                    Files.createFile(file.toPath());
                }
                try (FileOutputStream fos = new FileOutputStream(file, true)) {
                    for (Error err : errorList) {
                        String str = String.valueOf(err.getLineno()) + ' ' + err.getType() + '\n';
                        fos.write(str.getBytes());
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
                throw new RuntimeException("Error while writing tokens to file", e);
            }
        }
    }
}
