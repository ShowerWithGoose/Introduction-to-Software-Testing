package fronted.Lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Lexer {
    private String sourceCode;
    private int position = 0;
    private int lineNumber = 1;
    private ArrayList<Token> tokens = new ArrayList<>();
    private List<Error> errors = new ArrayList<>();

    public List<Error> getErrors() {
        return errors;
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    private final static Map<String, TokenType> specificWords = Map.ofEntries(
            Map.entry("main", TokenType.MAINTK),
            Map.entry("const", TokenType.CONSTTK),
            Map.entry("int", TokenType.INTTK),
            Map.entry("char", TokenType.CHARTK),
            Map.entry("break", TokenType.BREAKTK),
            Map.entry("continue", TokenType.CONTINUETK),
            Map.entry("if", TokenType.IFTK),
            Map.entry("else", TokenType.ELSETK),
            Map.entry("for", TokenType.FORTK),
            Map.entry("getint", TokenType.GETINTTK),
            Map.entry("getchar", TokenType.GETCHARTK),
            Map.entry("printf", TokenType.PRINTFTK),
            Map.entry("return", TokenType.RETURNTK),
            Map.entry("void", TokenType.VOIDTK)
    );

    public Lexer(String sourceCode) {
        this.sourceCode = sourceCode;
    }


    private char nextChar() {
        if (position < sourceCode.length()) {
            return sourceCode.charAt(position++);
        }
        return '\0'; // 表示结束
    }

    private char peekChar() {
        if (position < sourceCode.length()) {
            return sourceCode.charAt(position);
        }
        return '\0'; // 表示结束
    }

    private void backtrack() {
        position--;
    }

    public void tokenize() {
        String value;
        TokenType type;
        while (true) {
            char currentChar = nextChar();
            if (currentChar == '\0') break;

            if (currentChar == '\n') {
                lineNumber++;
                continue;
            }

            if (Character.isWhitespace(currentChar)) {
                continue;
            }

            // 处理标识符
            if (Character.isLetter(currentChar) || currentChar == '_') {
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                while (Character.isLetterOrDigit(peekChar()) || peekChar() == '_') {
                    sb.append(nextChar());
                }
                value = sb.toString();
                type = specificWords.getOrDefault(value, TokenType.IDENFR);
                tokens.add(new Token(type, value,lineNumber));
                continue;
            }
            else if(Character.isDigit(currentChar)){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                while (Character.isDigit(peekChar())) {
                    sb.append(nextChar());
                }
                value = sb.toString();
                tokens.add(new Token(TokenType.INTCON, value,lineNumber));
                continue;
            }
            else if(currentChar == '"'){
                StringBuilder strConst = new StringBuilder();
                strConst.append(currentChar);
                while ((currentChar = nextChar()) != '"') {
                    strConst.append(currentChar);
                }
                strConst.append(currentChar);
                tokens.add(new Token(TokenType.STRCON, strConst.toString(), lineNumber));
                continue;
            }
            else if(currentChar == '\''){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);  //第一个单引号
                if(peekChar() == '\\'){
                    currentChar = nextChar();   //如果单引号中有反斜杠，需要再读取一个
                    sb.append(currentChar);
                }
                currentChar = nextChar();    //正常再读单引号内的内容
                sb.append(currentChar);
                currentChar = nextChar();   //第二个单引号
                sb.append(currentChar);
                tokens.add(new Token(TokenType.CHRCON, sb.toString(), lineNumber));
                continue;
            }
            else if(currentChar == '!'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                if(peekChar() == '='){
                    currentChar = nextChar();   //如果单引号中有反斜杠，需要再读取一个
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.NEQ, value,lineNumber));
                }
                else{
                    value = sb.toString();
                    tokens.add(new Token(TokenType.NOT, value,lineNumber));
                }
                continue;
            }
            else if(currentChar == '|'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                currentChar = nextChar();
                if(currentChar == '|'){
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.OR, value,lineNumber));
                    continue;
                }
                else{
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.OR, value,lineNumber));
                    backtrack();
                    errors.add(new Error(lineNumber, "a"));
                    continue;
                }
            }
            else if(currentChar == '&'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                currentChar = nextChar();
                if(currentChar == '&'){
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.AND, value,lineNumber));
                    continue;
                }
                else{
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.AND, value,lineNumber));
                    backtrack();
                    errors.add(new Error(lineNumber, "a"));
                    continue;
                }
            }
            else if(currentChar == '+'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.PLUS, value,lineNumber));
                continue;
            }
            else if(currentChar == '-'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.MINU, value,lineNumber));
                continue;
            }
            else if(currentChar == '*'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.MULT, value,lineNumber));
                continue;
            }
            else if(currentChar == '/'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                if (peekChar() == '/') { // 单行注释
                    nextChar(); // 跳过第二个 '/'
                    while (currentChar != '\n' && currentChar != '\0') {
                        currentChar = nextChar();
                    }
                    backtrack();
                    continue; // 跳过注释内容
                } else if (peekChar() == '*') { // 多行注释
                    nextChar(); // 跳过 '*'
                    while (true) {
                        currentChar = nextChar();
                        if (currentChar == '\n') {
                            lineNumber++;
                        }
                        if (currentChar == '*' && peekChar() == '/') {
                            nextChar(); // 跳过 '/'
                            break; // 结束多行注释
                        }
                    }
                    continue; // 跳过注释内容
                } else {
                    value = sb.toString();
                    tokens.add(new Token(TokenType.DIV, value,lineNumber));
                    continue;
                }
            }
            else if(currentChar == '%'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.MOD, value,lineNumber));
                continue;
            }
            else if(currentChar == '<'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                if (peekChar() == '=') {
                    currentChar = nextChar();
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.LEQ, value,lineNumber));
                    continue;
                }
                else{
                    value = sb.toString();
                    tokens.add(new Token(TokenType.LSS, value,lineNumber));
                    continue;
                }
            }
            else if(currentChar == '>'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                if (peekChar() == '=') {
                    currentChar = nextChar();
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.GEQ, value,lineNumber));
                    continue;
                }
                else{
                    value = sb.toString();
                    tokens.add(new Token(TokenType.GRE, value,lineNumber));
                    continue;
                }
            }
            else if(currentChar == '='){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                if (peekChar() == '=') {
                    currentChar = nextChar();
                    sb.append(currentChar);
                    value = sb.toString();
                    tokens.add(new Token(TokenType.EQL, value,lineNumber));
                    continue;
                }
                else{
                    value = sb.toString();
                    tokens.add(new Token(TokenType.ASSIGN, value,lineNumber));
                    continue;
                }
            }
            else if(currentChar == ';'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.SEMICN, value,lineNumber));
                continue;
            }
            else if(currentChar == ','){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.COMMA, value,lineNumber));
                continue;
            }
            else if(currentChar == '('){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.LPARENT, value,lineNumber));
                continue;
            }
            else if(currentChar == ')'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.RPARENT, value,lineNumber));
                continue;
            }
            else if(currentChar == '['){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.LBRACK, value,lineNumber));
                continue;
            }
            else if(currentChar == ']'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.RBRACK, value,lineNumber));
                continue;
            }
            else if(currentChar == '{'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.LBRACE, value,lineNumber));
                continue;
            }
            else if(currentChar == '}'){
                StringBuilder sb = new StringBuilder();
                sb.append(currentChar);
                value = sb.toString();
                tokens.add(new Token(TokenType.RBRACE, value,lineNumber));
                continue;
            }

            // 处理错误
            errors.add(new Error(lineNumber, "INVALID_OP"));
        }
    }

    public void output() throws IOException {
        try (FileWriter lexerFile = new FileWriter("lexer.txt");
             FileWriter errorFile = new FileWriter("error.txt")) {

            if (errors.isEmpty()) {
                for (Token token : tokens) {
                    lexerFile.write(token.type + " " + token.value + "\n");
                }
            }
            else {
                for (Error error : errors) {
                    errorFile.write(error.line + " " + error.code + "\n");
                }
            }

        }
    }



}
