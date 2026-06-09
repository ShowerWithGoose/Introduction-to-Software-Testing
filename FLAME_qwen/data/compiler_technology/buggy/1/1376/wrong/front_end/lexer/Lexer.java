package front_end.lexer;

import exception.CompilerError;
import exception.ErrorTackle;

import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private String input;
    private int position;
    private ArrayList<Token> tokens;
    private HashMap<Integer,Integer> tokenPosToLine;

    public Lexer(String input) {
        this.input = input;
        this.position = 0;
        this.tokens = new ArrayList<>();
        this.tokenPosToLine = new HashMap<>();
        run();
    }

    private char next() {
        if (position >= input.length()) {
            position++;
            return '\0';
        }
        return input.charAt(position++);
    }

    private void back() {
        position--;
    }

    private void run() {
        Token token;
        do {
            token=tokenStart();
        } while (token==null);
        while (token.getType() != TokenType.EOF) {
            tokens.add(token);
            tokenPosToLine.put(tokens.size()-1,getLine(position));
            do {
                token = tokenStart();
            } while (token == null);
        }
        ErrorTackle.setTokenPosToLine(tokenPosToLine);
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Token token : tokens) {
            if (token == null) {
                continue;
            }
            result.append(token.getType());
            result.append(" ");
            result.append(token.toString());
            result.append("\n");
        }
        return result.toString();
    }

    // 获取某个position所处的行数
    public int getLine(int position) {
        int line = 1;
        for (int i = 0; i < position; i++) {
            if (i > input.length() - 1) {
                return line;
            }
            if (input.charAt(i) == '\n') {
                line++;
            }
        }
        return line;
    }

    private Token tokenStart() {
        char c = next();
        while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            c = next();
        }
        StringBuilder token = new StringBuilder();
        while (c != '\0') {
            switch (c) {
                case ';':
                    return new Token(TokenType.SEMICN, ";");
                case '[':
                    return new Token(TokenType.LBRACK, "[");
                case ']':
                    return new Token(TokenType.RBRACK, "]");
                case '(':
                    return new Token(TokenType.LPARENT, "(");
                case ')':
                    return new Token(TokenType.RPARENT, ")");
                case '{':
                    return new Token(TokenType.LBRACE, "{");
                case '}':
                    return new Token(TokenType.RBRACE, "}");
                case '+':
                    return new Token(TokenType.PLUS, "+");
                case '-':
                    return new Token(TokenType.MINU, "-");
                case '*':
                    return new Token(TokenType.MULT, "*");
                case '/':
                    c = next();
                    if (c == '/') {
                        while (c != '\n' && c != '\0') {
                            c = next();
                        }
                        return null;
                    }
                    if (c == '*') {
                        c = next();
                        while (c != '\0') {
                            if (c == '*') {
                                c = next();
                                if (c == '/') {
                                    break;
                                }
                            }
                            c = next();
                        }
                        return null;
                    }
                    back();
                    return new Token(TokenType.DIV, "/");
                case '%':
                    return new Token(TokenType.MOD, "%");
                case '=':
                    c = next();
                    if (c == '=') {
                        return new Token(TokenType.EQL, "==");
                    }
                    back();
                    return new Token(TokenType.ASSIGN, "=");
                case '!':
                    c = next();
                    if (c == '=') {
                        return new Token(TokenType.NEQ, "!=");
                    }
                    back();
                    return new Token(TokenType.NOT, "!");
                case '>':
                    c = next();
                    if (c == '=') {
                        return new Token(TokenType.GEQ, ">=");
                    }
                    back();
                    return new Token(TokenType.GRE, ">");
                case '<':
                    c = next();
                    if (c == '=') {
                        return new Token(TokenType.LEQ, "<=");
                    }
                    back();
                    return new Token(TokenType.LSS, "<");
                case '&':
                    c = next();
                    if (c == '&') {
                        return new Token(TokenType.AND, "&&");
                    }
                    ErrorTackle.addError(new CompilerError(getLine(position), "a"));
                    back();
                    return new Token(TokenType.AND, "&&");
                case '|':
                    c = next();
                    if (c == '|') {
                        return new Token(TokenType.OR, "||");
                    }
                    ErrorTackle.addError(new CompilerError(getLine(position), "a"));
                    back();
                    return new Token(TokenType.OR, "||");
//                    throw new Exception("Invalid character");
                case ',':
                    return new Token(TokenType.COMMA, ",");
                case '"':
                    c = next();
                    while (c != '"') {
                        if (c == '\\') {
                            c = next();
                            switch (c) {
                                case 'n':
                                    token.append("\n");
                                    break;
                                case 't':
                                    token.append("\t");
                                    break;
                                case '\\':
                                    token.append("\\");
                                    break;
                                case '\'':
                                    token.append("'");
                                    break;
                                case '0':
                                    token.append("\0");
                                    break;
                                case '"':
                                    token.append("\"");
                                    break;
                                case 'a':
                                    token.append("\007");
                                    break;
                                case 'b':
                                    token.append("\b");
                                    break;
                                case 'f':
                                    token.append("\f");
                                    break;
                                case 'v':
                                    token.append("\013");
                                    break;
                                default:
                                    c=next();
                                    return null;
                            }
                        } else {
                            token.append(c);
                        }
                        c = next();
                    }
                    return new Token(TokenType.STRCON, token.toString());
                case '\'':
                    c = next();
                    if (c == '\\') {
                        c = next();
                        next();
                        return switch (c) {
                            case 'n' -> new Token(TokenType.CHRCON, "\n");
                            case 't' -> new Token(TokenType.CHRCON, "\t");
                            case '\\' -> new Token(TokenType.CHRCON, "\\");
                            case '\'' -> new Token(TokenType.CHRCON, "'");
                            case '"' -> new Token(TokenType.CHRCON, "\"");
                            case '0' -> new Token(TokenType.CHRCON, "\0");
                            case 'r' -> new Token(TokenType.CHRCON, "\r");
                            case 'b' -> new Token(TokenType.CHRCON, "\b");
                            case 'f' -> new Token(TokenType.CHRCON, "\f");
                            case 'a' -> new Token(TokenType.CHRCON, "\007");
                            case 'v' -> new Token(TokenType.CHRCON, "\013");
                            default -> {
                                c = next();
                                yield null;
                            }
                        };
                    }
                    if (c == '\'') {
                        c=next();
                        return null;
                    }
                    char temp = c;
                    c = next();
                    return new Token(TokenType.CHRCON, String.valueOf(temp));
                default:
                    if (Character.isDigit(c)) {
                        do {
                            token.append(c);
                            c = next();
                        } while (Character.isDigit(c));
                        back();
                        return new Token(TokenType.INTCON, token.toString());
                    }
                    if (Character.isLetter(c) || c == '_') {
                        do {
                            token.append(c);
                            c = next();
                        } while (Character.isLetter(c) || Character.isDigit(c) || c == '_');
                        String value = token.toString();
                        back();
                        return switch (value) {
                            case "int" -> new Token(TokenType.INTTK, value);
                            case "char" -> new Token(TokenType.CHARTK, value);
                            case "void" -> new Token(TokenType.VOIDTK, value);
                            case "const" -> new Token(TokenType.CONSTTK, value);
                            case "if" -> new Token(TokenType.IFTK, value);
                            case "else" -> new Token(TokenType.ELSETK, value);
                            case "for" -> new Token(TokenType.FORTK, value);
                            case "break" -> new Token(TokenType.BREAKTK, value);
                            case "continue" -> new Token(TokenType.CONTINUETK, value);
                            case "return" -> new Token(TokenType.RETURNTK, value);
                            case "main" -> new Token(TokenType.MAINTK, value);
                            case "getint" -> new Token(TokenType.GETINTTK, value);
                            case "getchar" -> new Token(TokenType.GETCHARTK, value);
                            case "printf" -> new Token(TokenType.PRINTFTK, value);
                            default -> new Token(TokenType.IDENFR, value);
                        };
                    }
                    return new Token(TokenType.EOF, "");
//                throw new Exception("Invalid character");
            }
        }
        return new Token(TokenType.EOF, "");
    }
}
