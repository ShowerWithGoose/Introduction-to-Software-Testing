package mainSys;

import static mainSys.StaticValues.*;
import static mainSys.Tools.ParseTool.*;

public class Parser {
    public static String parseSTRCON() {
        StringBuilder sb = new StringBuilder();
        sb.append(getCharAndMove());
        while (!isEnd()) {
            if (getChar() == '\\' && pos + 1 < sourceCode.length()) {
                sb.append(getCharAndMove());
                sb.append(getCharAndMove());
            } else if (getChar() == '\"') {
                sb.append(getCharAndMove());
                break;
            } else {
                sb.append(getCharAndMove());
            }
        }
        tokens.add(new Token(STRCON, sb.toString()));
        return sb.toString();
    }

    public static void parseCHRCON() {
        StringBuilder sb = new StringBuilder();
        sb.append('\'');
        if (pos + 2 < sourceCode.length()) {
            // prepare for  further error checking
        }
        movePos();
        sb.append(getChar());
        if (getChar() == '\\') {
            sb.append(moveAndGetChar());
            sb.append('\'');
            movePos();
            movePos();
            tokens.add(new Token(CHRCON, sb.toString()));
        }else {
            sb.append(moveAndGetChar());
            movePos();
            tokens.add(new Token(CHRCON, sb.toString()));
        }
    }

    public static void parseINTCON() {
        StringBuilder sb = new StringBuilder();
        while (notEnd() && Character.isDigit(getChar())) {
            sb.append(getCharAndMove());
        }
        tokens.add(new Token(INTCON, sb.toString()));
    }

    public static void parseWord() {
        if (!parseKeywords()) {
            parseIDENFR();
        }
    }

    public static void parseIDENFR() {
        StringBuilder sb = new StringBuilder();
        while (notEnd() && isIdentChar(getChar())) {
            sb.append(getCharAndMove());
        }
        tokens.add(new Token(IDENFR, sb.toString()));
    }

    public static boolean parseKeywords() {
        for (String keyword : keywordMap.keySet()) {
            if (compareWordAndMovePos(keyword)) {
                tokens.add(new Token(keywordMap.get(keyword), keyword));
                return true;
            }
        }
        return false;
    }

    public static void parseSigns() {
        switch (getChar()) {
            case '!':
                if (moveAndGetChar() != '=') {
                    tokens.add(new Token(NOT, "!"));
                } else {
                    tokens.add(new Token(NEQ, "!="));
                    movePos();
                }
                break;
            case '&':
                tokens.add(new Token(AND, "&&"));
                if (moveAndGetChar() != '&') {
                    errors.add(new Error('a', line));
                } else {
                    movePos();
                }
                break;
            case '|':
                tokens.add(new Token(OR, "||"));
                if (moveAndGetChar() != '|') {
                    errors.add(new Error('a', line));
                } else {
                    movePos();
                }
                break;
            case '+':
                tokens.add(new Token(PLUS, "+"));
                movePos();
                break;
            case '-':
                tokens.add(new Token(MINU, "-"));
                movePos();
                break;
            case '*':
                tokens.add(new Token(MULT, "*"));
                movePos();
                break;
            case '/':
                if (!parseComments()) {
                    tokens.add(new Token(DIV, "/"));
                }
                break;
            case '%':
                tokens.add(new Token(MOD, "%"));
                movePos();
                break;
            case '<':
                if (moveAndGetChar() == '=') {
                    tokens.add(new Token(LEQ, "<="));
                    movePos();
                } else {
                    tokens.add(new Token(LSS, "<"));
                }
                break;
            case '>':
                if (moveAndGetChar() == '=') {
                    tokens.add(new Token(GEQ, ">="));
                    movePos();
                } else {
                    tokens.add(new Token(GRE, ">"));
                }
                break;
            case '=':
                if (moveAndGetChar() == '=') {
                    tokens.add(new Token(EQL, "=="));
                    movePos();
                } else {
                    tokens.add(new Token(ASSIGN, "="));
                }
                break;
            case ';':
                tokens.add(new Token(SEMICN, ";"));
                movePos();
                break;
            case '(':
                tokens.add(new Token(LPARENT, "("));
                movePos();
                break;
            case ')':
                tokens.add(new Token(RPARENT, ")"));
                movePos();
                break;
            case '{':
                tokens.add(new Token(LBRACE, "{"));
                movePos();
                break;
            case '}':
                tokens.add(new Token(RBRACE, "}"));
                movePos();
                break;
            case ',':
                tokens.add(new Token(COMMA, ","));
                movePos();
                break;
            case '[':
                tokens.add(new Token(LBRACK, "["));
                movePos();
                break;
            case ']':
                tokens.add(new Token(RBRACK, "]"));
                movePos();
                break;
            case '\r':
                movePos();
                break;
            default:
                System.out.println("Unexpected character: " + getChar());
                movePos();
                break;
        }
    }

    public static boolean notEnd() {
        return !isEnd();
    }

    public static boolean parseComments() {
        movePos();
        if (getChar() == '/') {
            while (!isEnd()) {
                if (moveAndGetChar() == '\n') {
                    movePos();
                    line++;
                    break;
                }
            }
            return true;
        } else if (getChar() == '*') {
            while (!isEnd()) {
                movePos();
                char c = getChar();
                if (getChar() == '*') {
                    movePos();
                    if (getChar() == '/') {
                        movePos();
                        return true;
                    } else if (getChar() == '\n') {
                        line++;
                    }
                } else if (getChar() == '\n') {
                    line++;
                }
            }
            return true;
        } else {
            return false;
        }
    }

}
