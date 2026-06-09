import java.io.*;
import java.util.*;

enum TokenType {
    // 标识符和常量
    IDENFR, INTCON, STRCON, CHRCON,

    // 保留字
    MAINTK, CONSTTK, INTTK, CHARTK, VOIDTK,
    IFTK, ELSETK, WHILETK, FORTK,
    BREAKTK, CONTINUETK, RETURNTK, PRINTFTK, SCANFTK,
    GETINTTK, GETCHARTK,

    // 操作符
    PLUS, MINU, MULT, DIV, MOD, ASSIGN,
    LSS, LEQ, GRE, GEQ, EQL, NEQ,
    AND, OR, NOT,

    // 符号
    COMMA, SEMICN, COLON, DOT,
    LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE,

    // 错误
    ERROR // 用于非法符号
}

class Token {
    TokenType type;
    String value;
    int line;

    public Token(TokenType type, String value, int line) {
        this.type = type;
        this.value = value;
        this.line = line;
    }
}

public class Lexer {
    private String source;
    private int curPos;
    private int lineNum;
    private Map<String, TokenType> reservedWords;
    private List<Token> tokens;
    private List<String> errors;

    public Lexer(String source) {
        this.source = source;
        this.curPos = 0;
        this.lineNum = 1;
        this.tokens = new ArrayList<>();
        this.errors = new ArrayList<>();
        this.reservedWords = new HashMap<>();
        initReservedWords();
    }

    private void initReservedWords() {
        reservedWords.put("main", TokenType.MAINTK);
        reservedWords.put("const", TokenType.CONSTTK);
        reservedWords.put("int", TokenType.INTTK);
        reservedWords.put("char", TokenType.CHARTK);
        reservedWords.put("void", TokenType.VOIDTK);
        reservedWords.put("if", TokenType.IFTK);
        reservedWords.put("else", TokenType.ELSETK);
        reservedWords.put("while", TokenType.WHILETK);
        reservedWords.put("for", TokenType.FORTK);
        reservedWords.put("break", TokenType.BREAKTK);
        reservedWords.put("continue", TokenType.CONTINUETK);
        reservedWords.put("return", TokenType.RETURNTK);
        reservedWords.put("printf", TokenType.PRINTFTK);
        reservedWords.put("scanf", TokenType.SCANFTK);
        reservedWords.put("getint", TokenType.GETINTTK);
        reservedWords.put("getchar", TokenType.GETCHARTK);
    }

    private char nextChar() {
        if (curPos < source.length()) {
            return source.charAt(curPos++);
        }
        return '\0';
    }

    public void lex() {
        char c;
        while ((c = nextChar()) != '\0') {
            if (Character.isWhitespace(c)) {
                if (c == '\n') lineNum++;
                continue;
            }
            // 处理注释
            if (c == '/') {
                if (curPos < source.length()) {
                    char nextChar = source.charAt(curPos);
                    // 处理单行注释
                    if (nextChar == '/') {
                        curPos++;
                        while (curPos < source.length() && source.charAt(curPos) != '\n') {
                            curPos++;
                        }
                        lineNum++;
                        continue;
                    }
                    // 处理多行注释
                    else if (nextChar == '*') {
                        curPos++;
                        boolean isEnd = false;
                        while (curPos < source.length()) {
                            if (source.charAt(curPos) == '*' && curPos + 1 < source.length() && source.charAt(curPos + 1) == '/') {
                                curPos += 2;
                                isEnd = true;
                                break;
                            }
                            if (source.charAt(curPos) == '\n') {
                                lineNum++;
                            }
                            curPos++;
                        }
                        if (!isEnd) {
                            errors.add(lineNum + " a");  // 未正确关闭的多行注释
                        }
                        continue;
                    }
                    // 非注释的除号
                    tokens.add(new Token(TokenType.DIV, "/", lineNum));
                    continue;
                }
            }

            // 处理标识符或关键字
            if (Character.isLetter(c) || c == '_') {
                StringBuilder tokenValue = new StringBuilder();
                tokenValue.append(c);
                while (curPos < source.length() &&
                        (Character.isLetterOrDigit(source.charAt(curPos)) || source.charAt(curPos) == '_')) {
                    tokenValue.append(nextChar());
                }
                String value = tokenValue.toString();
                if (reservedWords.containsKey(value)) {
                    tokens.add(new Token(reservedWords.get(value), value, lineNum));
                } else {
                    tokens.add(new Token(TokenType.IDENFR, value, lineNum));
                }
            }
            // 处理数字
            else if (Character.isDigit(c)) {
                StringBuilder tokenValue = new StringBuilder();
                tokenValue.append(c);
                while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                    tokenValue.append(nextChar());
                }
                tokens.add(new Token(TokenType.INTCON, tokenValue.toString(), lineNum));
            }
            // 处理字符串常量
            else if (c == '"') {
                StringBuilder tokenValue = new StringBuilder();
                tokenValue.append(c);
                while (curPos < source.length() && source.charAt(curPos) != '"') {
                    char next = nextChar();
                    if (next == '\n') {
                        errors.add(lineNum + " a");
                        lineNum++;
                        break;
                    }
                    tokenValue.append(next);
                }
                tokenValue.append(nextChar());  // 添加结束的 "
                tokens.add(new Token(TokenType.STRCON, tokenValue.toString(), lineNum));
            }
            // 处理字符常量
            else if (c == '\'') {
                StringBuilder tokenValue = new StringBuilder();
                tokenValue.append(c);
                if (curPos < source.length() && source.charAt(curPos) != '\'') {
                    tokenValue.append(nextChar());
                }
                if (curPos < source.length() && source.charAt(curPos) == '\'') {
                    tokenValue.append(nextChar());
                    tokens.add(new Token(TokenType.CHRCON, tokenValue.toString(), lineNum));
                } else {
                    errors.add(lineNum + " a");
                }
            }
            // 处理操作符和特殊符号
            else {
                switch (c) {
                    case '+': tokens.add(new Token(TokenType.PLUS, "+", lineNum)); break;
                    case '-': tokens.add(new Token(TokenType.MINU, "-", lineNum)); break;
                    case '*': tokens.add(new Token(TokenType.MULT, "*", lineNum)); break;
                    case '%': tokens.add(new Token(TokenType.MOD, "%", lineNum)); break; // 添加取模运算符
                    case '=':
                        if (curPos < source.length() && source.charAt(curPos) == '=') {
                            nextChar();
                            tokens.add(new Token(TokenType.EQL, "==", lineNum));
                        } else {
                            tokens.add(new Token(TokenType.ASSIGN, "=", lineNum));
                        }
                        break;
                    case '<':
                        if (curPos < source.length() && source.charAt(curPos) == '=') {
                            nextChar();
                            tokens.add(new Token(TokenType.LEQ, "<=", lineNum));
                        } else {
                            tokens.add(new Token(TokenType.LSS, "<", lineNum));
                        }
                        break;
                    case '>':
                        if (curPos < source.length() && source.charAt(curPos) == '=') {
                            nextChar();
                            tokens.add(new Token(TokenType.GEQ, ">=", lineNum));
                        } else {
                            tokens.add(new Token(TokenType.GRE, ">", lineNum));
                        }
                        break;
                    case '!':
                        if (curPos < source.length() && source.charAt(curPos) == '=') {
                            nextChar();
                            tokens.add(new Token(TokenType.NEQ, "!=", lineNum));
                        } else {
                            tokens.add(new Token(TokenType.NOT, "!", lineNum));
                        }
                        break;
                    case '&':
                        if (curPos < source.length() && source.charAt(curPos) == '&') {
                            nextChar();
                            tokens.add(new Token(TokenType.AND, "&&", lineNum));
                        } else {
                            errors.add(lineNum + " a");
                        }
                        break;
                    case '|':
                        if (curPos < source.length() && source.charAt(curPos) == '|') {
                            nextChar();
                            tokens.add(new Token(TokenType.OR, "||", lineNum));
                        } else {
                            errors.add(lineNum + " a");
                        }
                        break;
                    case ';': tokens.add(new Token(TokenType.SEMICN, ";", lineNum)); break;
                    case ',': tokens.add(new Token(TokenType.COMMA, ",", lineNum)); break;
                    case '(': tokens.add(new Token(TokenType.LPARENT, "(", lineNum)); break;
                    case ')': tokens.add(new Token(TokenType.RPARENT, ")", lineNum)); break;
                    case '[': tokens.add(new Token(TokenType.LBRACK, "[", lineNum)); break;
                    case ']': tokens.add(new Token(TokenType.RBRACK, "]", lineNum)); break;
                    case '{': tokens.add(new Token(TokenType.LBRACE, "{", lineNum)); break;
                    case '}': tokens.add(new Token(TokenType.RBRACE, "}", lineNum)); break;
                    default: errors.add(lineNum + " a");
                }
            }
        }
    }

    public void outputTokens(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Token token : tokens) {
                writer.write(token.type + " " + token.value);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void outputErrors(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (String error : errors) {
                writer.write(error);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        try {
            StringBuilder source = new StringBuilder();
            try (BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    source.append(line).append("\n");
                }
            }

            Lexer lexer = new Lexer(source.toString());
            lexer.lex();
            lexer.outputTokens("lexer.txt");
            lexer.outputErrors("error.txt");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
