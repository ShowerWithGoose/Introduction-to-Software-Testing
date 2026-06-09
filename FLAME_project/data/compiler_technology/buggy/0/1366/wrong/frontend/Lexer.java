package frontend;

import error.ErrorType;

public class Lexer {
    private String source;
    private int lineNum = 1;
    private int curPos = 0;
    private LexType lexType;
    private Token token = null;

    public Lexer(String sourceCode) {
        source = sourceCode;
    }

    public Token getToken() {
        return token;
    }

    public boolean hasNext() {
        StringBuilder sb = new StringBuilder();
        String value;
        LexType type;
        char c;
        token = null;
        if (curPos < source.length())
        {
            c = source.charAt(curPos);
        } else {
            return false;
        }
        while (curPos < source.length()) {
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
                curPos++;
                if (c == '\n') {
                    lineNum++;
                }
                if (curPos < source.length()) {
                    c = source.charAt(curPos);
                } else return false;
            } else break;
        }
        if (Character.isDigit(c)) {
            while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                // 下一个符号是数字
                c = source.charAt(curPos++);
                sb.append(c);
            }
            type = LexType.INTCON; // 设置单词类别
            token = new Token(type, lineNum, sb.toString());
        } else if (Character.isLetter(c) || c == '_') {
            while (curPos < source.length() &&
                    (Character.isLetter(source.charAt(curPos)) ||
                            Character.isDigit(source.charAt(curPos)) ||
                            source.charAt(curPos) == '_')) {
                c = source.charAt(curPos++);
                sb.append(c);
            }
            value = sb.toString();
            type = judgeLexType(value);
            token = new Token(type, lineNum, value);
        } else if (c == '(') {
            token = new Token(LexType.LPARENT, lineNum, "(");
            curPos++;
        } else if (c == '[') {
            token = new Token(LexType.LBRACK, lineNum, "[");
            curPos++;
        } else if (c == '{') {
            token = new Token(LexType.LBRACE, lineNum, "{");
            curPos++;
        } else if (c == ')') {
            token = new Token(LexType.RPARENT, lineNum, ")");
            curPos++;
        }  else if (c == ']') {
            token = new Token(LexType.RBRACK, lineNum, "]");
            curPos++;
        } else if (c == '}') {
            token = new Token(LexType.RBRACE, lineNum, "}");
            curPos++;
        } else if (c == ';') {
            token = new Token(LexType.SEMICN, lineNum, ";");
            curPos++;
        } else if (c == ',') {
            token = new Token(LexType.COMMA, lineNum, ",");
            curPos++;
        } else if (c == '+') {
            token = new Token(LexType.PLUS, lineNum, "+");
            curPos++;
        } else if (c == '-') {
            token = new Token(LexType.MINU, lineNum, "-");
            curPos++;
        } else if (c == '*') {
            token = new Token(LexType.MULT, lineNum, "*");
            curPos++;
        } else if (c == '%') {
            token = new Token(LexType.MOD, lineNum, "%");
            curPos++;
        } else if (c == '!') {
            curPos++;
            if (source.charAt(curPos) != '=')
            {
                token = new Token(LexType.NOT, lineNum, "!");
            }
            else {
                token = new Token(LexType.NEQ, lineNum, "!=");
                curPos++;
            }

        } else if (c == '&') {
            curPos++;
            if (source.charAt(curPos) == '&') {
                token = new Token(LexType.AND,lineNum,"&&");
                curPos++;
            }
            else {
                token = new Token(ErrorType.ILLEGAL_AND_OR,lineNum,"&");
            }
        } else if (c == '|') {
            curPos++;
            if (source.charAt(curPos) == '|') {
                token = new Token(LexType.OR,lineNum,"||");
                curPos++;
            }
            else {
                token = new Token(ErrorType.ILLEGAL_AND_OR,lineNum,"|");
            }
        } else if (c=='"'){
            sb.append(c);
            curPos++;
            c = source.charAt(curPos);
            while (c != '"'){
                sb.append(c);
                curPos++;
                c=source.charAt(curPos);
            }
            sb.append(c);
            token = new Token(LexType.STRCON,lineNum,sb.toString());
            curPos++;
        } else if (c == '\'') {
            sb.append(c);
            curPos++;
            c = source.charAt(curPos);
            if (c == '\\') {
                sb.append(c);
                curPos++;
                sb.append(source.charAt(curPos));
                curPos++;
            }
            while (source.charAt(curPos) != '\'') {
                sb.append(source.charAt(curPos));
                curPos++;
            }
            sb.append(source.charAt(curPos));
            curPos++;
            token = new Token(LexType.CHRCON,lineNum,sb.toString());
        }  else if (c == '>') {
            sb.append(c);
            curPos++;
            if (source.charAt(curPos) == '=') {
                sb.append(source.charAt(curPos));
                curPos++;
                token = new Token(LexType.GEQ,lineNum,sb.toString());
            }
            else {
                token = new Token(LexType.GRE,lineNum,sb.toString());
            }
        } else if (c == '<') {
            sb.append(c);
            curPos++;
            if (source.charAt(curPos) == '=') {
                sb.append(source.charAt(curPos));
                curPos++;
                token = new Token(LexType.LEQ, lineNum, sb.toString());
            } else {
                token = new Token(LexType.LSS, lineNum, sb.toString());
            }
        } else if (c == '=') {
            sb.append(c);
            curPos++;
            if (source.charAt(curPos) == '=') {
                sb.append(source.charAt(curPos));
                curPos++;
                token = new Token(LexType.EQL, lineNum, sb.toString());
            } else {
                token = new Token(LexType.ASSIGN, lineNum, sb.toString());
            }
        } else if (c == '/') {
            curPos++;
            sb.append(c);
            if (source.charAt(curPos) == '/') {
                curPos++;
                c = source.charAt(curPos);
                while (c!='\n'){
                    if (curPos==source.length()){
                        token = null;
                        break;
                    }
                    curPos++;
                    c=source.charAt(curPos);

                }
                if (c == '\n') {
                    lineNum++;
                    curPos++;
                }
                if (token == null && curPos < source.length()) {
                    hasNext();
                }
            } else if (source.charAt(curPos) == '*') {
                sb.append(source.charAt(curPos));
                curPos++;
                while (!(source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
                    if (source.charAt(curPos) == '\n') {
                        lineNum++;
                    }
                    curPos++;
                }
                curPos = curPos + 2;
                hasNext();
            }
            else {
                token = new Token(LexType.DIV,lineNum,sb.toString());
            }
        }
        if (curPos < source.length() && token == null) {
            hasNext();
        } else if (curPos == source.length() && token == null) {
            return false;
        }
        return true;

    }

    private LexType judgeLexType(String value) {
        if (value.equals("main")) {
            return LexType.MAINTK;
        }
        if (value.equals("const")) {
            return LexType.CONSTTK;
        }
        if (value.equals("int")) {
            return LexType.INTTK;
        }
        if (value.equals("char")) {
            return LexType.CHARTK;
        }
        if (value.equals("break")) {
            return LexType.BREAKTK;
        }
        if (value.equals("continue")) {
            return LexType.CONTINUETK;
        }
        if (value.equals("if")) {
            return LexType.IFTK;
        }
        if (value.equals("else")) {
            return LexType.ELSETK;
        }
        if (value.equals("for")) {
            return LexType.FORTK;
        }
        if (value.equals("getint")) {
            return LexType.GETINTTK;
        }
        if (value.equals("getchar")) {
            return LexType.GETCHARTK;
        }
        if (value.equals("printf")) {
            return LexType.PRINTFTK;
        }
        if (value.equals("return")) {
            return LexType.RETURNTK;
        }
        if (value.equals("void")) {
            return LexType.VOIDTK;
        }
        return LexType.IDENFR;
    }

    private boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
}
