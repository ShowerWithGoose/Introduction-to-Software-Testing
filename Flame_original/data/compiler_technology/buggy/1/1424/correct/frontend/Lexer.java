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

    public Lexer(Scanner scanner, ArrayList<Error> errors) {
        this.scanner = scanner;
        tokens = new ArrayList<>();
        this.errors = errors;
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

    public void run() {
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
                    tokens.add(new Token(TokenType.INTCON, token, i + 1));
                } else if (ch == '\'') {
                    token = "'";
                    boolean tag = false;
                    while(getChar()) {
                        token += ch;
                        if (tag) {
                            tag = false;
                        } else {
                            if (ch == '\\') {
                                tag = !tag;
                            } else if (ch == '\'') {
                                break;
                            }
                        }
                    }
                    tokens.add(new Token(TokenType.CHRCON, token, i + 1));
                } else if (ch == '\"') {
                    token = "\"";
                    boolean tag = false;
                    while(getChar()) {
                        token += ch;
                        if (tag) {
                            tag = false;
                        } else {
                            if (ch == '\\') {
                                tag = !tag;
                            } else if (ch == '\"') {
                                break;
                            }
                        }
                    }
                    tokens.add(new Token(TokenType.STRCON, token, i + 1));
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
                            tokens.add(new Token(TokenType.MAINTK, token, i + 1));
                            break;
                        }
                        case "const" : {
                            tokens.add(new Token(TokenType.CONSTTK, token, i + 1));
                            break;
                        }
                        case "int" : {
                            tokens.add(new Token(TokenType.INTTK, token, i + 1));
                            break;
                        }
                        case "char" : {
                            tokens.add(new Token(TokenType.CHARTK, token, i + 1));
                            break;
                        }
                        case "break" : {
                            tokens.add(new Token(TokenType.BREAKTK, token, i + 1));
                            break;
                        }
                        case "continue" : {
                            tokens.add(new Token(TokenType.CONTINUETK, token, i + 1));
                            break;
                        }
                        case "if" : {
                            tokens.add(new Token(TokenType.IFTK, token, i + 1));
                            break;
                        }
                        case "else" : {
                            tokens.add(new Token(TokenType.ELSETK, token, i + 1));
                            break;
                        }
                        case "for" : {
                            tokens.add(new Token(TokenType.FORTK, token, i + 1));
                            break;
                        }
                        case "getint" : {
                            tokens.add(new Token(TokenType.GETINTTK, token, i + 1));
                            break;
                        }
                        case "getchar" : {
                            tokens.add(new Token(TokenType.GETCHARTK, token, i + 1));
                            break;
                        }
                        case "printf" : {
                            tokens.add(new Token(TokenType.PRINTFTK, token, i + 1));
                            break;
                        }
                        case "return" : {
                            tokens.add(new Token(TokenType.RETURNTK, token, i + 1));
                            break;
                        }
                        case "void" : {
                            tokens.add(new Token(TokenType.VOIDTK, token, i + 1));
                            break;
                        }
                        default: {
                            tokens.add(new Token(TokenType.IDENFR, token, i + 1));
                            break;
                        }
                    }
                } else if (ch == '!') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.NEQ, "!=", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.NOT, "!", i + 1));
                        pos = t;
                    }
                } else if (ch == '&') {
                    int t = pos;
                    if (getChar() && ch == '&') {
                        tokens.add(new Token(TokenType.AND, "&&", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.AND, "&", i + 1));
                        errors.add(new Error(i + 1, "a"));
                        pos = t;
                    }
                } else if (ch == '|') {
                    int t = pos;
                    if (getChar() && ch == '|') {
                        tokens.add(new Token(TokenType.OR, "||", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.OR, "|", i + 1));
                        errors.add(new Error(i + 1, "a"));
                        pos = t;
                    }
                } else if (ch == '+') {
                    tokens.add(new Token(TokenType.PLUS, "+", i + 1));
                } else if (ch == '-') {
                    tokens.add(new Token(TokenType.MINU, "-", i + 1));
                } else if (ch == '*') {
                    tokens.add(new Token(TokenType.MULT, "*", i + 1));
                } else if (ch == '/') {
                    tokens.add(new Token(TokenType.DIV, "/", i + 1));
                } else if (ch == '%') {
                    tokens.add(new Token(TokenType.MOD, "%", i + 1));
                } else if (ch == '<') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.LEQ, "<=", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.LSS, "<", i + 1));
                        pos = t;
                    }
                } else if (ch == '>') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.GEQ, ">=", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.GRE, ">", i + 1));
                        pos = t;
                    }
                } else if (ch == '=') {
                    int t = pos;
                    if (getChar() && ch == '=') {
                        tokens.add(new Token(TokenType.EQL, "==", i + 1));
                    } else {
                        tokens.add(new Token(TokenType.ASSIGN, "=", i + 1));
                        pos = t;
                    }
                } else if (ch == ';') {
                    tokens.add(new Token(TokenType.SEMICN, ";", i + 1));
                } else if (ch == ',') {
                    tokens.add(new Token(TokenType.COMMA, ",", i + 1));
                } else if (ch == '(') {
                    tokens.add(new Token(TokenType.LPARENT, "(", i + 1));
                } else if (ch == ')') {
                    tokens.add(new Token(TokenType.RPARENT, ")", i + 1));
                } else if (ch == '[') {
                    tokens.add(new Token(TokenType.LBRACK, "[", i + 1));
                } else if (ch == ']') {
                    tokens.add(new Token(TokenType.RBRACK, "]", i + 1));
                } else if (ch == '{') {
                    tokens.add(new Token(TokenType.LBRACE, "{", i + 1));
                } else if (ch == '}') {
                    tokens.add(new Token(TokenType.RBRACE, "}", i + 1));
                }
            }
        }
    }

}
