package frontend;

import java.util.ArrayList;

public class Lexer {
    private Input input;
    private ArrayList<Token> tokens;
    private ArrayList<Error> errors;
    private int tableLen;
    private String[] symTable;
    private String str_temp;
    private TokenType type_temp;
    private boolean flag;
    private Character ch;

    public Lexer(Input input, ArrayList<Token> tokens, ArrayList<Error> errors) {
        this.input = input;
        this.tokens = tokens;
        this.errors = errors;
        tableLen = 37;
        symTable = new String[] {
                "!",        "!=",       "%",        "&&",       "(",
                ")",        "*",        "+",        ",",        "-",
                "/",        ";",        "<",        "<=",       "=",
                "==",       ">",        ">=",       "[",        "]",
                "break",    "char",     "const",    "continue", "else",
                "for",      "getchar",  "getint",   "if",       "int",
                "main",     "printf",   "return",   "void",     "{",
                "||",       "}"
        };
        str_temp = "";
        type_temp = null;
        flag = true;
        ch = null;
    }

    public boolean lexer() {
        flag = true;
        ch = input.getChar();

        while (!input.isEnd()) {
            if (nextSym()) {
                Token token = new Token(type_temp, str_temp);
                //System.out.println(str_temp);
                tokens.add(token);
            }
        }

        return flag;
    }

    private boolean nextSym() {
        StringBuilder stringBuilder = new StringBuilder();
        String string;
        while (!input.isEnd()) {
            if (Character.isWhitespace(ch)) {
                ch = input.getChar();

            } else if (Character.isAlphabetic(ch)) {
                Integer index_table;
                stringBuilder.append(ch);

                while (!input.isEnd()) {
                    ch = input.getChar();
                    if (Character.isAlphabetic(ch) || Character.isDigit(ch) || ch == '_') {
                        stringBuilder.append(ch);
                    } else {
                        break;
                    }
                }

                string = stringBuilder.toString();
                index_table = issym(string);
                if (index_table >= 0) {
                    str_temp = string;
                    type_temp = getType(index_table);
                    return true;
                } else {
                    str_temp = string;
                    type_temp = TokenType.IDENFR;
                    return true;
                }

            } else if (ch == '_') {
                stringBuilder.append(ch);

                while (!input.isEnd()) {
                    ch = input.getChar();
                    if (Character.isAlphabetic(ch) || Character.isDigit(ch) || ch == '_') {
                        stringBuilder.append(ch);
                    } else {
                        break;
                    }
                }

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.IDENFR;
                return true;

            } else if (Character.isDigit(ch)) {
                stringBuilder.append(ch);

                while (!input.isEnd()) {
                    ch = input.getChar();
                    if (Character.isDigit(ch)) {
                        stringBuilder.append(ch);
                    } else {
                        break;
                    }
                }

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.INTCON;
                return true;

            } else if (ch == '!') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch != '=') {
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.NOT;
                    return true;
                } else {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.NEQ;
                    return true;
                }

            } else if (ch == '&') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch == '&') {
                    stringBuilder.append(ch);
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.AND;
                    return true;
                } else {
                    Error error = new Error('a', input.getLine());
                    errors.add(error);

                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.AND;
                    flag = false;
                    return true;
                }

            } else if (ch == '|') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch == '|') {
                    stringBuilder.append(ch);
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.AND;
                    return true;
                } else {
                    Error error = new Error('a', input.getLine());
                    errors.add(error);

                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.OR;
                    flag = false;
                    return true;
                }

            } else if (ch == '+') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.PLUS;
                return true;

            } else if (ch == '-') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.MINU;
                return true;

            } else if (ch == '*') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.MULT;
                return true;

            } else if (ch == '/') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.DIV;
                return true;

            } else if (ch == '%') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.MOD;
                return true;

            } else if (ch == '<') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch != '=') {
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.LSS;
                    return true;
                } else {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.LEQ;
                    return true;
                }

            } else if (ch == '>') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch != '=') {
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.GRE;
                    return true;
                } else {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.GEQ;
                    return true;
                }

            } else if (ch == '=') {
                stringBuilder.append(ch);
                ch = input.getChar();

                if (ch != '=') {
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.ASSIGN;
                    return true;
                } else {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                    string = stringBuilder.toString();
                    str_temp = string;
                    type_temp = TokenType.EQL;
                    return true;
                }

            } else if (ch == ';') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.SEMICN;
                return true;

            } else if (ch == ',') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.COMMA;
                return true;

            } else if (ch == '(') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.LPARENT;
                return true;

            } else if (ch == ')') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.RPARENT;
                return true;

            } else if (ch == '[') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.LBRACK;
                return true;

            } else if (ch == ']') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.RBRACK;
                return true;

            } else if (ch == '{') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.LBRACE;
                return true;

            } else if (ch == '}') {
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.RBRACE;
                return true;

            } else if (ch == '\"') {
                do {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                } while (ch != '\"');
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.STRCON;
                return true;

            } else if (ch == '\'') {
                do {
                    stringBuilder.append(ch);
                    ch = input.getChar();
                } while (ch != '\'');
                stringBuilder.append(ch);
                ch = input.getChar();

                string = stringBuilder.toString();
                str_temp = string;
                type_temp = TokenType.CHRCON;
                return true;

            } else {

            }
        }

        return false;
    }

    private int issym(String str) {
        Integer l = 0, r = tableLen - 1, mid;

        while (l <= r) {
            mid = (l + r) / 2;

            if (str.compareTo(symTable[mid]) == 0) {
                return mid;
            } else if (str.compareTo(symTable[mid]) > 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }

    private TokenType getType(int index_table) {
        switch (index_table) {
            case 0:
                return TokenType.NOT;
            case 1:
                return TokenType.NEQ;
            case 2:
                return TokenType.MOD;
            case 3:
                return TokenType.AND;
            case 4:
                return TokenType.LPARENT;
            case 5:
                return TokenType.RPARENT;
            case 6:
                return TokenType.MULT;
            case 7:
                return TokenType.PLUS;
            case 8:
                return TokenType.COMMA;
            case 9:
                return TokenType.MINU;
            case 10:
                return TokenType.DIV;
            case 11:
                return TokenType.SEMICN;
            case 12:
                return TokenType.LSS;
            case 13:
                return TokenType.LEQ;
            case 14:
                return TokenType.ASSIGN;
            case 15:
                return TokenType.EQL;
            case 16:
                return TokenType.GRE;
            case 17:
                return TokenType.GEQ;
            case 18:
                return TokenType.LBRACK;
            case 19:
                return TokenType.RBRACK;
            case 20:
                return TokenType.BREAKTK;
            case 21:
                return TokenType.CHARTK;
            case 22:
                return TokenType.CONSTTK;
            case 23:
                return TokenType.CONTINUETK;
            case 24:
                return TokenType.ELSETK;
            case 25:
                return TokenType.FORTK;
            case 26:
                return TokenType.GETCHARTK;
            case 27:
                return TokenType.GETINTTK;
            case 28:
                return TokenType.IFTK;
            case 29:
                return TokenType.INTTK;
            case 30:
                return TokenType.MAINTK;
            case 31:
                return TokenType.PRINTFTK;
            case 32:
                return TokenType.RETURNTK;
            case 33:
                return TokenType.VOIDTK;
            case 34:
                return TokenType.LBRACE;
            case 35:
                return TokenType.OR;
            case 36:
                return TokenType.RBRACE;
            default:
                break;
        }
        return null;
    }
}
