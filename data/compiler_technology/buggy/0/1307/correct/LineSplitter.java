import error_part.Error;
import error_part.ErrorList;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.time.format.SignStyle;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LineSplitter {
    private InputStream inputStream;
    private ArrayList<String> lines;
    private int curLineIndex;
    private int curCharIndex;

    public LineSplitter(InputStream inputStream) {
        this.inputStream = inputStream;
        lines = new ArrayList<>();
        curLineIndex = 0;
        curCharIndex = 0;
        split();
    }

    public void split() {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
        String cur_line;
        try {
            while (true) {
                cur_line = bufferedReader.readLine();
                if (cur_line == null) {
                    break;
                }
                lines.add(cur_line);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String getLine() {
        if (endFile()) {
            return "";
        }
        return lines.get(curLineIndex);
    }

    public char getChar() {
        if (endLine()) {
            return 0;
        }
        return getLine().charAt(curCharIndex);
    }

    public void skipSpace() {
        while (!endFile() && Character.isWhitespace(getChar())) {
            moveForward(1);
        }
        //System.out.println("after space cur line is " + getChar());
    }

    public void moveForward(int steps) {
        int cnt = steps;
        if (cnt > 0) {
            while (!endFile() && cnt > 0) {
                int lineLength = getLine().length();
                if (curCharIndex + steps >= lineLength) {
                    cnt -= (lineLength - curCharIndex + 1);
                    curLineIndex++;
                    curCharIndex = 0;
                } else {
                    curCharIndex += cnt;
                    cnt = 0;
                }
            }
        }
    }

    public boolean endFile() {
        return curLineIndex >= lines.size();
    }

    public boolean endLine() {
        return curCharIndex >= getLine().length();
    }

    public String getLineSubString(int len) {
        if (endFile()) {
            return "";
        }
        if (curCharIndex + len >= getLine().length()) {
            return getLine().substring(curCharIndex);
        } else {
            return getLine().substring(curCharIndex, curCharIndex + len);
        }
    }

    public void moveNextLine() {
        if (!endFile()) {
            curCharIndex = 0;
            curLineIndex++;
        }
    }

    public Token getToken() {
        Token.TokenType type;
        char curChar = getChar();
        StringBuilder sb = new StringBuilder(String.valueOf(curChar));
        type = getTokenType(curChar, sb);
        //moveForward(1);
        //System.out.println(type + " " + getChar());
        return new Token(type, sb.toString(), curLineIndex + 1);
    }

    public Token.TokenType getTokenType(char curChar, StringBuilder sb) {
        Token.TokenType type = null;
        if (curChar == '\'') {
            do {
                moveForward(1);
                sb.append(getChar());
                if (getChar() == '\\') {
                    moveForward(1);
                    sb.append(getChar());
                    moveForward(1);
                    sb.append(getChar());
                }
            } while (getChar() != '\'');
            type = Token.TokenType.CHRCON;
            moveForward(1);
        } else if (curChar == '"') {
            do {
                moveForward(1);
                sb.append(getChar());
                if (getChar() == '\\') {
                    moveForward(1);
                    sb.append(getChar());
                    moveForward(1);
                    sb.append(getChar());
                }
            } while (getChar() != '"');
            type = Token.TokenType.STRCON;
            moveForward(1);
        } else if (curChar == '!') {
            moveForward(1);
            if (getChar() == '=') {
                sb.append(getChar());
                type = Token.TokenType.NEQ;
                moveForward(1);
            } else {
                type = Token.TokenType.NOT;
            }
        } else if (curChar == '&') {
            moveForward(1);
            if (getChar() != '&') {
                ErrorList.addError(new Error(curLineIndex + 1, Error.ErrorType.ILLEGAL_AND_OR));
            } else {
                sb.append(getChar());
                moveForward(1);
            }
            type = Token.TokenType.AND;
        } else if (curChar == '|') {
            moveForward(1);
            if (getChar() != '|') {
                ErrorList.addError(new Error(curLineIndex + 1, Error.ErrorType.ILLEGAL_AND_OR));
            } else {
                sb.append(getChar());
                moveForward(1);
            }
            type = Token.TokenType.OR;
        } else if (curChar == '+') {
            type = Token.TokenType.PLUS;
            moveForward(1);
        } else if (curChar == '-') {
            type = Token.TokenType.MINU;
            moveForward(1);
        } else if (curChar == '*') {
            type = Token.TokenType.MULT;
            moveForward(1);
        } else if (curChar == '/') {
            type = Token.TokenType.DIV;
            moveForward(1);
        } else if (curChar == '%') {
            type = Token.TokenType.MOD;
            moveForward(1);
        } else if (curChar == '<') {
            moveForward(1);
            if (getChar() == '=') {
                sb.append(getChar());
                type = Token.TokenType.LEQ;
                moveForward(1);
            } else {
                type = Token.TokenType.LSS;
            }
        } else if (curChar == '>') {
            moveForward(1);
            if (getChar() == '=') {
                sb.append(getChar());
                type = Token.TokenType.GEQ;
                moveForward(1);
            } else {
                type = Token.TokenType.GRE;
            }

        } else if (curChar == '=') {
            moveForward(1);
            if (getChar() == '=') {
                sb.append(getChar());
                type = Token.TokenType.EQL;
                moveForward(1);
            } else {
                type = Token.TokenType.ASSIGN;
            }
        } else if (curChar == ';') {
            type = Token.TokenType.SEMICN;
            moveForward(1);
        } else if (curChar == ',') {
            type = Token.TokenType.COMMA;
            moveForward(1);
        } else if (curChar == '(') {
            type = Token.TokenType.LPARENT;
            moveForward(1);
        } else if (curChar == ')') {
            type = Token.TokenType.RPARENT;
            moveForward(1);
        } else if (curChar == '[') {
            type = Token.TokenType.LBRACK;
            moveForward(1);
        } else if (curChar == ']') {
            type = Token.TokenType.RBRACK;
            moveForward(1);
        } else if (curChar == '{') {
            type = Token.TokenType.LBRACE;
            moveForward(1);
        } else if (curChar == '}') {
            type = Token.TokenType.RBRACE;
            moveForward(1);
        } else if (Character.isDigit(curChar)) {
            sb.deleteCharAt(0);
            do {
                sb.append(getChar());
                moveForward(1);
            } while (Character.isDigit(getChar()));
            type = Token.TokenType.INTCON;
        } else if (Character.isAlphabetic(curChar) || curChar == '_') {
            sb.deleteCharAt(0);
            do {
                sb.append(getChar());
                moveForward(1);
            } while (Character.isAlphabetic(getChar()) || getChar() == '_' || Character.isDigit(getChar()));
            String word = sb.toString();
            type = switch (word) {
                case "int" -> Token.TokenType.INTTK;
                case "main" -> Token.TokenType.MAINTK;
                case "const" -> Token.TokenType.CONSTTK;
                case "char" -> Token.TokenType.CHARTK;
                case "break" -> Token.TokenType.BREAKTK;
                case "continue" -> Token.TokenType.CONTINUETK;
                case "if" -> Token.TokenType.IFTK;
                case "else" -> Token.TokenType.ELSETK;
                case "for" -> Token.TokenType.FORTK;
                case "getint" -> Token.TokenType.GETINTTK;
                case "getchar" -> Token.TokenType.GETCHARTK;
                case "printf" -> Token.TokenType.PRINTFTK;
                case "void" -> Token.TokenType.VOIDTK;
                case "return" -> Token.TokenType.RETURNTK;
                default -> Token.TokenType.IDENFR;
            };
            //System.out.println(curCharIndex + " " + type + " " + getChar());
        }
        return type;
    }

    public int getCurLineIndex() {
        return curLineIndex;
    }

    public int getCurCharIndex() {
        return curCharIndex;
    }
}
