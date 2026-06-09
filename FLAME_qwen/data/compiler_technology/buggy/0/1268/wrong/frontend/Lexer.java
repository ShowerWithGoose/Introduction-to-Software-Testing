package frontend;

import java.util.ArrayList;

public class Lexer {
    private ArrayList<Token> tokenList;
    private boolean correct;

    public Lexer() {
        this.tokenList = new ArrayList<>();
        this.correct = true;
    }

    public ArrayList<Token> parse(ArrayList<String> lines) {
        int lineNumber = 0;
        int i = 0;
        int j = 0;
        boolean flag = false;
        while (lineNumber < lines.size()) {
            int columnNumber = 0;
            if (flag) {
                lineNumber = i;
                columnNumber = j + 2;
                flag = false;
            }
            String line = lines.get(lineNumber);
            while (columnNumber < line.length()) {
                while (columnNumber < line.length() && Character.isWhitespace(line.charAt(columnNumber))) {
                    columnNumber++;
                }
                if (columnNumber == line.length()) {
                    break;
                }
                if (Character.isLetter(line.charAt(columnNumber))) {
                    StringBuilder sb = new StringBuilder();
                    while (columnNumber < line.length() && Character.isLetterOrDigit(line.charAt(columnNumber))) {
                        sb.append(line.charAt(columnNumber));
                        columnNumber++;
                    }
                    tokenList.add(new Token(word(sb.toString()), lineNumber, sb.toString()));
                    if (columnNumber == line.length()) {
                        break;
                    }
                }
                else if (Character.isDigit(line.charAt(columnNumber))) {
                    StringBuilder sb = new StringBuilder();
                    while (columnNumber < line.length() && Character.isDigit(line.charAt(columnNumber))) {
                        sb.append(line.charAt(columnNumber));
                        columnNumber++;
                    }
                    tokenList.add(new Token(TokenType.INTCON, lineNumber, sb.toString()));
                    if (columnNumber == line.length()) {
                        break;
                    }
                }
                else if (line.charAt(columnNumber) == '<') {
                    if (line.charAt(columnNumber + 1) == '=') {
                        tokenList.add(new Token(TokenType.LEQ, lineNumber, "<="));
                        columnNumber += 2;
                    }
                    else {
                        tokenList.add(new Token(TokenType.LSS, lineNumber, "<"));
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '>') {
                    if (line.charAt(columnNumber + 1) == '=') {
                        tokenList.add(new Token(TokenType.GEQ, lineNumber, ">="));
                        columnNumber += 2;
                    }
                    else {
                        tokenList.add(new Token(TokenType.GRE, lineNumber, ">"));
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '!') {
                    if (line.charAt(columnNumber + 1) == '=') {
                        tokenList.add(new Token(TokenType.NEQ, lineNumber, "!="));
                        columnNumber += 2;
                    }
                    else {
                        tokenList.add(new Token(TokenType.NOT, lineNumber, "!"));
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '=') {
                    if (line.charAt(columnNumber + 1) == '=') {
                        tokenList.add(new Token(TokenType.EQL, lineNumber, "=="));
                        columnNumber += 2;
                    }
                    else {
                        tokenList.add(new Token(TokenType.ASSIGN, lineNumber, "="));
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '&') {
                    if (line.charAt(columnNumber + 1) == '&') {
                        tokenList.add(new Token(TokenType.AND, lineNumber, "&&"));
                        columnNumber += 2;
                    }
                    else {
                        correct = false;
                        Error error = new Error(lineNumber + 1, "a");
                        ErrorList.addError(error);
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '|') {
                    if (line.charAt(columnNumber + 1) == '|') {
                        tokenList.add(new Token(TokenType.OR, lineNumber, "||"));
                        columnNumber += 2;
                    }
                    else {
                        correct = false;
                        Error error = new Error(lineNumber + 1, "a");
                        ErrorList.addError(error);
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '+') {
                    tokenList.add(new Token(TokenType.PLUS, lineNumber, "+"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '-') {
                    tokenList.add(new Token(TokenType.MINU, lineNumber, "-"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '*') {
                    tokenList.add(new Token(TokenType.MULT, lineNumber, "*"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '/') {
                    if (line.charAt(columnNumber + 1) == '/') {
                        lineNumber++;
                        break;
                    }
                    else if (line.charAt(columnNumber + 1) == '*') {
                        i = lineNumber;
                        j = columnNumber + 2;
                        while (i < lines.size()) {
                            while (j < lines.get(i).length()) {
                                if (lines.get(i).charAt(j) == '*' && lines.get(i).charAt(j + 1) == '/') {
                                    flag = true;
                                    break;
                                }
                                j++;
                            }
                            if (flag) {
                                break;
                            }
                            j = 0;
                            i++;
                        }
                        if (!flag) {
                            return this.tokenList;
                        }
                        break;
                    }
                    else {
                        tokenList.add(new Token(TokenType.DIV, lineNumber, "/"));
                        columnNumber++;
                    }
                }
                else if (line.charAt(columnNumber) == '%') {
                    tokenList.add(new Token(TokenType.MOD, lineNumber, "%"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == ';') {
                    tokenList.add(new Token(TokenType.SEMICN, lineNumber, ";"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == ',') {
                    tokenList.add(new Token(TokenType.COMMA, lineNumber, ","));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '(') {
                    tokenList.add(new Token(TokenType.LPARENT, lineNumber, "("));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == ')') {
                    tokenList.add(new Token(TokenType.RPARENT, lineNumber, ")"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '[') {
                    tokenList.add(new Token(TokenType.LBRACK, lineNumber, "["));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == ']') {
                    tokenList.add(new Token(TokenType.RBRACK, lineNumber, "]"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '{') {
                    tokenList.add(new Token(TokenType.LBRACE, lineNumber, "{"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '}') {
                    tokenList.add(new Token(TokenType.RBRACE, lineNumber, "}"));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '"') {
                    columnNumber++;
                    StringBuilder sb = new StringBuilder();
                    sb.append('"');
                    while (line.charAt(columnNumber) != '"') {
                        sb.append(line.charAt(columnNumber));
                        columnNumber++;
                    }
                    sb.append('"');
                    tokenList.add(new Token(TokenType.STRCON, lineNumber, sb.toString()));
                    columnNumber++;
                }
                else if (line.charAt(columnNumber) == '\'') {
                    columnNumber++;
                    StringBuilder sb = new StringBuilder();
                    sb.append('\'');
                    while (line.charAt(columnNumber) != '\'') {
                        sb.append(line.charAt(columnNumber));
                        columnNumber++;
                    }
                    sb.append('\'');
                    tokenList.add(new Token(TokenType.CHARCON, lineNumber, sb.toString()));
                    columnNumber++;
                }
            }
            lineNumber++;
        }
        return this.tokenList;
    }

    private TokenType word(String content) {
        if (content.equals("main")) {
            return TokenType.MAINTK;
        }
        else if (content.equals("const")) {
            return TokenType.CONSTTK;
        }
        else if (content.equals("int")) {
            return TokenType.INTTK;
        }
        else if (content.equals("char")) {
            return TokenType.CHARTK;
        }
        else if (content.equals("break")) {
            return TokenType.BREAKTK;
        }
        else if (content.equals("continue")) {
            return TokenType.CONTINUETK;
        }
        else if (content.equals("if")) {
            return TokenType.IFTK;
        }
        else if (content.equals("else")) {
            return TokenType.ELSETK;
        }
        else if (content.equals("for")) {
            return TokenType.FORTK;
        }
        else if (content.equals("getint")) {
            return TokenType.GETINTTK;
        }
        else if (content.equals("getchar")) {
            return TokenType.GETCHARTK;
        }
        else if (content.equals("printf")) {
            return TokenType.PRINTFTK;
        }
        else if (content.equals("return")) {
            return TokenType.RETURNTK;
        }
        else {
            return TokenType.IDENFR;
        }
    }

    public boolean getCorrect() {
        return correct;
    }
}
