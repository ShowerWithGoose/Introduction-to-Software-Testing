package frontend;

import error.Error;
import error.ErrorList;
import error.ErrorType;
import token.TokenType;
import token.Token;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Lexer {
    private static Lexer instance;
    private String text;
    private List<Token> tokenList;

    public static Lexer getInstance() {
        if (instance == null) {
            instance = new Lexer();
        }
        return instance;
    }

    public void setText(String text) {
        this.text = text;
    }

    public List<Token> getTokenList() {
        return tokenList;
    }

    public String getTokenListAsString() {
        StringBuilder builder = new StringBuilder();
        for (Token token : tokenList) {
            builder.append(token.toString());
        }
        return builder.toString();
    }

    private final HashMap<String, TokenType> keywords = new HashMap<>() {
        {
            put("main", TokenType.MAINTK);
            put("const", TokenType.CONSTTK);
            put("int", TokenType.INTTK);
            put("char", TokenType.CHARTK);
            put("break", TokenType.BREAKTK);
            put("continue", TokenType.CONTINUETK);
            put("if", TokenType.IFTK);
            put("else", TokenType.ELSETK);
            put("for", TokenType.FORTK);
            put("getint", TokenType.GETINTTK);
            put("getchar", TokenType.GETCHARTK);
            put("printf", TokenType.PRINTFTK);
            put("return", TokenType.RETURNTK);
            put("void", TokenType.VOIDTK);
        }
    };

    public void getToken() {
        tokenList = new ArrayList<>();
        int line = 1;                                   // 记录行数
        int len = text.length();                        // 源程序长度

        for (int i = 0; i < len; i++) {
            char c = text.charAt(i);
            char nextc = i + 1 < len ? text.charAt(i + 1) : '\0';
            StringBuilder str = new StringBuilder();

            if (c == ' ' || c == '\t' || c == '\n') {
                /* whitespace */
                if (c == '\n')  line++;
            } else if (Character.isLetter(c) || c == '_') {
                /* keyword or identifier */
                for (int j = i; j < len; j++) {
                    char cc = text.charAt(j);
                    if (Character.isLetter(cc) || Character.isDigit(cc) || cc == '_') {
                        str.append(cc);
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                tokenList.add(new Token(keywords.getOrDefault(str.toString(), TokenType.IDENFR), str.toString(), line));
            } else if (Character.isDigit(c)) {
                /* integer */
                for (int j = i; j < len; j++) {
                    char cc = text.charAt(j);
                    if (Character.isDigit(cc)) {
                        str.append(cc);
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                tokenList.add(new Token(TokenType.INTCON, str.toString(), line));
            } else if (c == '\"') {
                str.append(c);
                for (int j = i + 1; j < len; j++) {
                    char cc = text.charAt(j);
                    if (cc == '\\') {
                        j++;
                        str.append("\\").append(text.charAt(j));
                    } else if (cc != '\"') {
                        str.append(cc);
                    } else {
                        i = j;
                        str.append("\"");
                        break;
                    }
                }
                tokenList.add(new Token(TokenType.STRCON, str.toString(), line));
            } else if (c == '\'') {
                str.append(c);
                if (nextc == '\\') {
                    i += 2;
                    char cc = text.charAt(i);
                    str.append("\\").append(cc);
                } else {
                    i++;
                    str.append(nextc);
                }
                str.append('\'');
                i++;
                tokenList.add(new Token(TokenType.CHRCON, str.toString(), line));
            } else if (c == '!') {
                /* ! or != */
                str.append(c);
                if (nextc == '=') {
                    str.append(nextc);
                    i++;
                    tokenList.add(new Token(TokenType.NEQ, "!=", line));
                } else {
                    tokenList.add(new Token(TokenType.NOT, "!", line));
                }
            } else if (c == '&') {
                /* && */
                str.append(c);
                if (nextc == '&') {
                    str.append(nextc);
                    i++;
                } else {
                    ErrorList.getInstance().addError(new Error(line, ErrorType.a));
                }
                tokenList.add(new Token(TokenType.AND, "&&", line));
            } else if (c == '|') {
                /* || */
                str.append(c);
                if (nextc == '|') {
                    str.append(nextc);
                    i++;
                } else {
                    ErrorList.getInstance().addError(new Error(line, ErrorType.a));
                }
                tokenList.add(new Token(TokenType.OR, "||", line));
            } else if (c == '+') tokenList.add(new Token(TokenType.PLUS, "+", line));
            else if (c == '-') tokenList.add(new Token(TokenType.MINU, "-", line));
            else if (c == '*') tokenList.add(new Token(TokenType.MULT, "*", line));
            else if (c == '/') {
                /* / or /* or // */
                if (nextc == '/') {
                    for (int j = i + 1; j < len; j++) {
                        char cc = text.charAt(j);
                        if (cc =='\n') {
                            i = j - 1;
                            break;
                        }
                    }
                } else if (nextc == '*') {
                    for (int j = i + 2; j < len; j++) {
                        char cc = text.charAt(j);
                        if (cc =='\n')  line++;
                        else if (cc == '*' && text.charAt(j + 1) == '/') {
                            i = j + 1;
                            break;
                        }
                    }
                } else {
                    tokenList.add(new Token(TokenType.DIV, "/", line));
                }
            } else if (c == '%') tokenList.add(new Token(TokenType.MOD, "%", line));
            else if (c == '<') {
                /* < or <= */
                if (nextc == '=') {
                    i++;
                    tokenList.add(new Token(TokenType.LEQ, "<=", line));
                } else {
                    tokenList.add(new Token(TokenType.LSS, "<", line));
                }
            } else if (c == '>') {
                /* > or >= */
                if (nextc == '=') {
                    i++;
                    tokenList.add(new Token(TokenType.GEQ, ">=", line));
                } else {
                    tokenList.add(new Token(TokenType.GRE, ">", line));
                }
            } else if (c == '=') {
                /* = or == */
                if (nextc == '=') {
                    i++;
                    tokenList.add(new Token(TokenType.EQL, "==", line));
                } else {
                    tokenList.add(new Token(TokenType.ASSIGN, "=", line));
                }
            } else if (c == ';') tokenList.add(new Token(TokenType.SEMICN, ";", line));
            else if (c == ',') tokenList.add(new Token(TokenType.COMMA, ",", line));
            else if (c == '(') tokenList.add(new Token(TokenType.LPARENT, "(", line));
            else if (c == ')') tokenList.add(new Token(TokenType.RPARENT, ")", line));
            else if (c == '[') tokenList.add(new Token(TokenType.LBRACK, "[", line));
            else if (c == ']') tokenList.add(new Token(TokenType.RBRACK, "]", line));
            else if (c == '{') tokenList.add(new Token(TokenType.LBRACE, "{", line));
            else if (c == '}') tokenList.add(new Token(TokenType.RBRACE, "}", line));
        }

    }

}
