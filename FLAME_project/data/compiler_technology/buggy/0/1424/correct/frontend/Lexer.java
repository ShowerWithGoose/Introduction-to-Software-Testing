package frontend;

import java.util.ArrayList;
import java.util.Scanner;

public class Lexer {

    private Scanner scanner;
    private ArrayList<Token> tokens;
    private ArrayList<Error> errors;
    private String code;
    private int pos;
    private char ch;

    public Lexer(Scanner scanner) {
        this.scanner = scanner;
        tokens = new ArrayList<>();
        errors = new ArrayList<>();
        code = "";
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }

    private boolean getChar() {
        if (pos < code.length()) {
            ch = code.charAt(pos++);
            return true;
        }
        return false;
    }

    private boolean getNext() {
        int ori = pos;
        while (getChar() && Character.isWhitespace(ch));
        return ori != pos;
    }

    private ArrayList<String> getCode() {
        ArrayList<String> codes = new ArrayList<>();
        int status = 0;
        while (scanner.hasNext()) {
            String code = scanner.nextLine();
            String code1 = "";
            for (int i = 0; i < code.length(); i++) {
                char ch = code.charAt(i);
                if (status == 0) {
                    if (ch == '/') {
                        status = 1;
                    } else {
                        code1 += ch;
                    }
                } else if (status == 1) {
                    if (ch == '*') {
                        status = 2;
                    } else if (ch == '/') {
                        status = 0;
                        break;
                    } else {
                        code1 += "/" + ch;
                        status = 0;
                    }
                } else if (status == 2) {
                    if (ch == '*') {
                        status = 3;
                    }
                } else {
                    if (ch == '/') {
                        status = 0;
                    } else if (ch != '*') {
                        status = 2;
                    }
                }
            }
            if (status == 1) {
                code1 += "/";
                status = 0;
            } else if (status == 3) {
                status = 2;
            }
            codes.add(code1);
        }
        return codes;
    }

    public boolean run() {
        boolean error = false;
        ArrayList<String> codes = getCode();
        for (int i = 0; i < codes.size(); i++) {
            code = codes.get(i);
            pos = 0;
            while (getNext()) {
                String token;
                if (Character.isDigit(ch)) {
                    token = "";
                    do {
                        token += ch;
                    } while(getChar() && Character.isDigit(ch));
                    if (!Character.isDigit(ch)) {
                        pos--;
                    }
                    tokens.add(new Token(TokenType.INTCON, token));
                } else if (ch == '\'') {
                    token = "'";
                    while(getChar() && ch != '\'') {
                        token += ch;
                    }
                    token += "'";
                    tokens.add(new Token(TokenType.CHRCON, token));
                } else if (ch == '"') {
                    token = "\"";
                    while(getChar() && ch != '"') {
                        token += ch;
                    }
                    token += "\"";
                    tokens.add(new Token(TokenType.STRCON, token));
                } else if (Character.isLetter(ch) || ch == '_') {
                    token = "";
                    do {
                        token += ch;
                    } while(getChar() && (Character.isLetter(ch) || ch == '_' || Character.isDigit(ch)));
                    if (!(Character.isLetter(ch) || ch == '_' || Character.isDigit(ch))) {
                        pos--;
                    }
                    switch (token) {
                        case "main": {
                            tokens.add(new Token(TokenType.MAINTK, token));
                            break;
                        }
                        case "const" : {
                            tokens.add(new Token(TokenType.CONSTTK, token));
                            break;
                        }
                        case "int" : {
                            tokens.add(new Token(TokenType.INTTK, token));
                            break;
                        }
                        case "char" : {
                            tokens.add(new Token(TokenType.CHARTK, token));
                            break;
                        }
                        case "break" : {
                            tokens.add(new Token(TokenType.BREAKTK, token));
                            break;
                        }
                        case "continue" : {
                            tokens.add(new Token(TokenType.CONTINUETK, token));
                            break;
                        }
                        case "if" : {
                            tokens.add(new Token(TokenType.IFTK, token));
                            break;
                        }
                        case "else" : {
                            tokens.add(new Token(TokenType.ELSETK, token));
                            break;
                        }
                        case "for" : {
                            tokens.add(new Token(TokenType.FORTK, token));
                            break;
                        }
                        case "getint" : {
                            tokens.add(new Token(TokenType.GETINTTK, token));
                            break;
                        }
                        case "getchar" : {
                            tokens.add(new Token(TokenType.GETCHARTK, token));
                            break;
                        }
                        case "printf" : {
                            tokens.add(new Token(TokenType.PRINTFTK, token));
                            break;
                        }
                        case "return" : {
                            tokens.add(new Token(TokenType.RETURNTK, token));
                            break;
                        }
                        case "void" : {
                            tokens.add(new Token(TokenType.VOIDTK, token));
                            break;
                        }
                        default: {
                            tokens.add(new Token(TokenType.IDENFR, token));
                            break;
                        }
                    }
                } else if (ch == '!') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.NEQ, "!="));
                    } else {
                        tokens.add(new Token(TokenType.NOT, "!"));
                        pos = t;
                    }
                } else if (ch == '&') {
                    int t = pos;
                    if (getChar() && ch == '&') {
                        tokens.add(new Token(TokenType.AND, "&&"));
                    } else {
                        tokens.add(new Token(TokenType.AND, "&"));
                        error = true;
                        errors.add(new Error(i + 1, "a"));
                        pos = t;
                    }
                } else if (ch == '|') {
                    int t = pos;
                    if (getChar() && ch == '|') {
                        tokens.add(new Token(TokenType.OR, "||"));
                    } else {
                        tokens.add(new Token(TokenType.OR, "|"));
                        error = true;
                        errors.add(new Error(i + 1, "a"));
                        pos = t;
                    }
                } else if (ch == '+') {
                    tokens.add(new Token(TokenType.PLUS, "+"));
                } else if (ch == '-') {
                    tokens.add(new Token(TokenType.MINU, "-"));
                } else if (ch == '*') {
                    tokens.add(new Token(TokenType.MULT, "*"));
                } else if (ch == '/') {
                    tokens.add(new Token(TokenType.DIV, "/"));
                } else if (ch == '%') {
                    tokens.add(new Token(TokenType.MOD, "%"));
                } else if (ch == '<') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.LEQ, "<="));
                    } else {
                        tokens.add(new Token(TokenType.LSS, "<"));
                        pos = t;
                    }
                } else if (ch == '>') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.GEQ, ">="));
                    } else {
                        tokens.add(new Token(TokenType.GRE, ">"));
                        pos = t;
                    }
                } else if (ch == '=') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.EQL, "=="));
                    } else {
                        tokens.add(new Token(TokenType.ASSIGN, "="));
                        pos = t;
                    }
                } else if (ch == ';') {
                    tokens.add(new Token(TokenType.SEMICN, ";"));
                } else if (ch == ',') {
                    tokens.add(new Token(TokenType.COMMA, ","));
                } else if (ch == '(') {
                    tokens.add(new Token(TokenType.LPARENT, "("));
                } else if (ch == ')') {
                    tokens.add(new Token(TokenType.RPARENT, ")"));
                } else if (ch == '[') {
                    tokens.add(new Token(TokenType.LBRACK, "["));
                } else if (ch == ']') {
                    tokens.add(new Token(TokenType.RBRACK, "]"));
                } else if (ch == '{') {
                    tokens.add(new Token(TokenType.LBRACE, "{"));
                } else if (ch == '}') {
                    tokens.add(new Token(TokenType.RBRACE, "}"));
                }
            }
        }
        return error;
    }

}
