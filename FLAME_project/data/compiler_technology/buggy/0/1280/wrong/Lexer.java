import java.awt.*;
import java.io.*;
import java.util.*;

public class Lexer {

    private final BufferedReader reader;
    private int currentChar;
    private int lineNumber = 1;
    private int columnNumber = 1;

    private ArrayList<Word> words = new ArrayList<>();

    private ArrayList<Error> errors = new ArrayList<>();

    private static final Map<String, Type> keywords = new HashMap<>();
    static {
        keywords.put("main", Type.MAINTK);
        keywords.put("const", Type.CONSTTK);
        keywords.put("int", Type.INTTK);
        keywords.put("char", Type.CHARTK);
        keywords.put("break", Type.BREAKTK);
        keywords.put("continue", Type.CONTINUETK);
        keywords.put("if", Type.IFTK);
        keywords.put("else", Type.ELSETK);
        keywords.put("!", Type.NOT);
        keywords.put("&&", Type.AND);
        keywords.put("||", Type.OR);
        keywords.put("for", Type.FORTK);
        keywords.put("getint", Type.GETINTTK);
        keywords.put("getchar", Type.GETCHARTK);
        keywords.put("printf", Type.PRINTFTK);
        keywords.put("return", Type.RETURNTK);
        keywords.put("+", Type.PLUS);
        keywords.put("-", Type.MINU);
        keywords.put("void", Type.VOIDTK);
        keywords.put("*", Type.MULT);
        keywords.put("/", Type.DIV);
        keywords.put("%", Type.MOD);
        keywords.put("<", Type.LSS);
        keywords.put("<=", Type.LEQ);
        keywords.put(">", Type.GRE);
        keywords.put(">=", Type.GEQ);
        keywords.put("==", Type.EQL);
        keywords.put("!=", Type.NEQ);
        keywords.put("=", Type.ASSIGN);
        keywords.put(";", Type.SEMICN);
        keywords.put(",", Type.COMMA);
        keywords.put("(", Type.LPARENT);
        keywords.put(")", Type.RPARENT);
        keywords.put("[", Type.LBRACK);
        keywords.put("]", Type.RBRACK);
        keywords.put("{", Type.LBRACE);
        keywords.put("}", Type.RBRACE);
    }

    private static final Set<Character> singles = new HashSet<>();
    static {
        singles.add('(');
        singles.add(')');
        singles.add('[');
        singles.add(']');
        singles.add('{');
        singles.add('}');
        singles.add(';');
        singles.add(',');
        singles.add('+');
        singles.add('-');
        singles.add('*');
        singles.add('%');
    }

    private static final Set<Character> multi = new HashSet<>();
    static {
        multi.add('<');
        multi.add('>');
        multi.add('=');
        multi.add('!');
    }

    private static final Set<Character> logical = new HashSet<>();
    static {
        logical.add('&');
        logical.add('|');
    }

    public Lexer(String filePath) throws IOException {
        reader = new BufferedReader(new FileReader(filePath));
        currentChar = reader.read();
    }

    public void close() throws IOException {
        reader.close();
    }

    public void analyze() throws IOException {
        while (currentChar != -1) {    //未读取到结尾
            skipWhiteSpace();               //跳过空白
            if (currentChar == -1) {
                break;
            }

            if (Character.isLetter(currentChar) || currentChar == '_') {
                identWord();    //字母或下划线打头，标识符
            } else if (Character.isDigit(currentChar)) {   //数字打头
                identInteger();
            } else if (currentChar == '"' || currentChar == '\'') {   //字符或字符串常量
                identChars();
            } else if (currentChar == '/') {    //可能是注释
                exeg();
            } else if (singles.contains((char) currentChar)) {  //可单独成词
                String token = String.valueOf((char) currentChar);
                words.add(new Word(lineNumber, columnNumber, token, keywords.get(token)));
                advance();
            } else if (multi.contains((char) currentChar)){
                identMult();
            } else if (logical.contains((char) currentChar)) {
                identLogical();
            } else {
                System.out.printf("Error : invalid input in line %d column %d%n", lineNumber, columnNumber);
                advance();
            }
        }
    }

    private void exeg() throws IOException {
        int line = lineNumber;
        int column = columnNumber;

        advance();
        if (currentChar == '/') {   //双行注释
            while (currentChar != '\n') {   //跳过当前行
                advance();
            }
            advance();
        } else if (currentChar == '*') {    //多行注释
            while (true) {
                if (currentChar == '*') {
                    advance();
                    if (currentChar == '/') {   //结束多行注释
                        break;
                    }
                } else {
                    advance();
                }
            }
            advance();
        } else {    //只是单独的除号
            words.add(new Word(line, column, "/", Type.DIV));
        }
    }

    private void identLogical() throws IOException {
        int line = lineNumber;
        int column = columnNumber;
        if (currentChar == '&') {
            advance();
            if (currentChar != '&') {
                errors.add(new Error(line, column, 'a'));
            } else {
                words.add(new Word(line, column, "&&", Type.AND));
                advance();
            }
        } else if (currentChar == '|') {
            advance();
            if (currentChar != '|') {
                errors.add(new Error(line, column, 'a'));
            } else {
                words.add(new Word(line, column, "||", Type.OR));
                advance();
            }
        } else {
            System.out.println("Error : not Logical Char");
        }
    }

    private void identMult() throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        int line = lineNumber;
        int column = columnNumber;

        Type type = currentChar == '<' ? Type.LSS :
                currentChar == '>' ? Type.GRE :
                        currentChar == '=' ? Type.ASSIGN :
                                currentChar == '!' ? Type.NOT : Type.error;

        if (type == Type.error) {
            System.out.println("Error : not Mult Char");
            return ;
        }

        stringBuilder.append((char) currentChar);
        advance();
        if (currentChar == '=') {
            type = type == Type.LSS ? Type.LEQ :
                        type == Type.GRE ? Type.GEQ :
                            type == Type.ASSIGN ? Type.EQL :
                                    Type.NEQ;
            stringBuilder.append((char) currentChar);
            advance();
        }
        words.add(new Word(line, column, stringBuilder.toString(), type));

    }

    private void identChars() throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        int line = lineNumber;
        int column = columnNumber;

        if (currentChar == '"') {   //字符串常量
            do {
                stringBuilder.append((char) currentChar);
                advance();
            } while (currentChar != '"');
            stringBuilder.append((char) currentChar);
            words.add(new Word(line, column, stringBuilder.toString(), Type.STRCON));
            advance();
        } else if (currentChar == '\'') {   //字符常量
            do {
                stringBuilder.append((char) currentChar);
                advance();
            } while (currentChar != '\'');
            stringBuilder.append((char) currentChar);
            words.add(new Word(line, column, stringBuilder.toString(), Type.CHRCON));
            advance();
        } else {
            System.out.printf("Error : Not char or String in line %d column %d%n", line, column);
        }
    }
    
    private void identInteger() throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        int line = lineNumber;
        int column = columnNumber;

        while (currentChar != -1 && Character.isDigit(currentChar)) {
            stringBuilder.append((char) currentChar);
            advance();
        }
        String token = stringBuilder.toString();
        words.add(new Word(line, column, token, Type.INTCON));
    }

    private void identWord() throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        int line = lineNumber;
        int column = columnNumber;

        while (currentChar != -1 &&
                (Character.isLetterOrDigit(currentChar) || currentChar == '_')) {
            stringBuilder.append((char) currentChar);
            advance();
        }

        String token = stringBuilder.toString();
        words.add(new Word(line, column, token, keywords.getOrDefault(token, Type.IDENFR)));
    }

    private void skipWhiteSpace() throws IOException{
        while (currentChar != -1 && Character.isWhitespace(currentChar)) {
            advance();
        }
    }

    private void advance() throws IOException {
        if (currentChar == '\n') {         //更新行列信息
            lineNumber = lineNumber + 1;
            columnNumber = 1;
        } else if (currentChar != -1) {
            columnNumber = columnNumber + 1;
        }
        currentChar = reader.read();            //读取下一字符
    }

    public void output() throws FileNotFoundException {
        String errorPath = "error.txt";
        String lexerPath = "lexer.txt";
        if (errors.isEmpty()) {
            System.setOut(new PrintStream(lexerPath));
            for (Word word : words) {
                System.out.printf("%s %s%n", word.getType().toString(), word.getValue());
            }
        } else {
            System.setOut(new PrintStream(errorPath));
            for (Error error : errors) {
                System.out.printf("%d %c%n", error.getLineNumber(), error.getErrorCode());
            }
        }
    }
}
