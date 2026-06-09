package frontend;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Lexer {
    private final String input;
    private List<Token> tokens;
    private HashMap<String, TokenType> reservedWord;
    private int pos = 0;
    private String curToken;
    private HashMap<Integer, Character> error;
    private int isMany;

    public Lexer(String input) {
        this.input = input;
        this.tokens = new ArrayList<>();
        this.reservedWord = new HashMap<>() {{
            put("main", TokenType.MAINTK);
            put("const", TokenType.CONSTTK);
            put("int", TokenType.INTTK);
            put("char", TokenType.CHARTK);
            put("break", TokenType.BREAKTK);
            put("continue", TokenType.BREAKTK);
            put("if", TokenType.IFTK);
            put("else", TokenType.ELSETK);
            put("for", TokenType.FORTK);
            put("getint", TokenType.GETINTTK);
            put("getchar", TokenType.GETCHARTK);
            put("printf", TokenType.PRINTFTK);
            put("return", TokenType.RETURNTK);
            put("void", TokenType.VOIDTK);
        }};
        this.error = new HashMap<>();
        this.isMany = 0;
    }

    public void posZero(){
        pos = 0;
    }

    private String getNumber(String input) {
        StringBuilder sb = new StringBuilder();
        while (pos < input.length() && Character.isDigit(input.charAt(pos))) {
            sb.append(input.charAt(pos));
            ++pos;
        }
        return sb.toString();
    }

    private String getIdent(String input) {
        StringBuilder sb = new StringBuilder();
        while (pos < input.length() &&
                (Character.isAlphabetic(input.charAt(pos)) || Character.isDigit(input.charAt(pos)) || input.charAt(pos) == '_')) {
            sb.append(input.charAt(pos));
            ++pos;
        }
        return sb.toString();
    }

    private String getStringCons(String input) {
        StringBuilder sb = new StringBuilder();
        sb.append("\"");
        while (pos < input.length() && input.charAt(pos) != '"') {
            sb.append(input.charAt(pos));
            ++pos;
        }
        sb.append(input.charAt(pos));
        pos++;
        return sb.toString();
    }

    private String getCharCons(String input) {
        StringBuilder sb = new StringBuilder();
        sb.append("'");
        pos++;
        sb.append(input.charAt(pos));
        pos++;
        sb.append(input.charAt(pos));
        pos++;
        return sb.toString();
    }

    private void clearToken() {
        curToken = "";
    }

    public List<Token> getTokens() {
        return tokens;
    }

    public boolean isRight() {
        return error.isEmpty();
    }

    public void getSymbol(String input, int lineNumber) {
        while (pos < input.length()) {
            if (isMany == 1) {
                while (pos < input.length() && !(input.charAt(pos) == '*' && pos + 1 < input.length() && input.charAt(pos + 1) == '/')) {
                    pos++;
                }
                if (pos == input.length()) {
                    continue;
                } else {
                    pos = pos + 2;
                    isMany = 0;
                }
            }
            clearToken();
            while (input.charAt(pos) == ' ' || input.charAt(pos) == '\n' || input.charAt(pos) == '\t') {
                pos++;
            }
            Token token;
            if (Character.isAlphabetic(input.charAt(pos)) || input.charAt(pos) == '_') {
                curToken = getIdent(input);
                if (reservedWord.containsKey(curToken)) {
                    token = new Token(reservedWord.get(curToken), curToken, lineNumber);
                } else {
                    token = new Token(TokenType.IDENFR, curToken, lineNumber);
                }
                tokens.add(token);
            } else if (Character.isDigit(input.charAt(pos))) {
                curToken = getNumber(input);
                token = new Token(TokenType.INTCON, curToken, lineNumber);
                tokens.add(token);
            } else if (input.charAt(pos) == '+') {
                token = new Token(TokenType.PLUS, "+", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '-') {
                token = new Token(TokenType.MINU, "-", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '*') {
                token = new Token(TokenType.MULT, "*", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '%') {
                token = new Token(TokenType.MOD, "%", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == ';') {
                token = new Token(TokenType.SEMICN, ";", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == ',') {
                token = new Token(TokenType.COMMA, ",", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '(') {
                token = new Token(TokenType.LPARENT, "(", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == ')') {
                token = new Token(TokenType.RPARENT, ")", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '[') {
                token = new Token(TokenType.LBRACK, "[", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == ']') {
                token = new Token(TokenType.RBRACK, "]", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '{') {
                token = new Token(TokenType.LBRACE, "{", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '}') {
                token = new Token(TokenType.RBRACE, "}", lineNumber);
                tokens.add(token);
                pos++;
            } else if (input.charAt(pos) == '!') {
                pos++;
                if (input.charAt(pos) == '=') {
                    token = new Token(TokenType.NEQ, "!=", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    token = new Token(TokenType.NOT, "!", lineNumber);
                    tokens.add(token);
                }
            } else if (input.charAt(pos) == '<') {
                pos++;
                if (input.charAt(pos) == '=') {
                    token = new Token(TokenType.LEQ, "<=", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    token = new Token(TokenType.LSS, "<", lineNumber);
                    tokens.add(token);
                }
            } else if (input.charAt(pos) == '>') {
                pos++;
                if (input.charAt(pos) == '=') {
                    token = new Token(TokenType.GEQ, ">=", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    token = new Token(TokenType.GRE, ">", lineNumber);
                    tokens.add(token);
                }
            } else if (input.charAt(pos) == '=') {
                pos++;
                if (input.charAt(pos) == '=') {
                    token = new Token(TokenType.EQL, "==", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    token = new Token(TokenType.ASSIGN, "=", lineNumber);
                    tokens.add(token);
                }
            } else if (input.charAt(pos) == '/') {
                pos++;
                if (input.charAt(pos) == '/') {
                    break;
                } else if (input.charAt(pos) == '*') {
                    pos++;
                    while (pos < input.length() && !(input.charAt(pos) == '*' && pos + 1 < input.length() && input.charAt(pos + 1) == '/')) {
                        pos++;
                    }
                    if (pos == input.length()) {
                        isMany = 1;
                    } else {
                        pos = pos + 2;
                    }
                } else {
                    token = new Token(TokenType.DIV, "/", lineNumber);
                    tokens.add(token);
                }
            } else if (input.charAt(pos) == '&') {
                pos++;
                if (input.charAt(pos) == '&') {
                    token = new Token(TokenType.AND, "&&", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    error.put(1, 'a');
                    try (FileOutputStream fos = new FileOutputStream("error.txt");
                         PrintWriter writer = new PrintWriter(fos)) {
                        writer.printf("%d a\n", lineNumber);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            } else if (input.charAt(pos) == '|') {
                pos++;
                if (input.charAt(pos) == '|') {
                    token = new Token(TokenType.OR, "||", lineNumber);
                    tokens.add(token);
                    pos++;
                } else {
                    error.put(1, 'a');
                    try (FileOutputStream fos = new FileOutputStream("error.txt");
                         PrintWriter writer = new PrintWriter(fos)) {
                        writer.printf("%d a\n", lineNumber);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            } else if (input.charAt(pos) == '"') {
                pos++;
                curToken = getStringCons(input);
                token = new Token(TokenType.STRCON, curToken, lineNumber);
                tokens.add(token);
            } else if (input.charAt(pos) == '\'') {
                curToken = getCharCons(input);
                token = new Token(TokenType.CHRCON, curToken, lineNumber);
                tokens.add(token);
            }
        }
    }
}
