package frontend;

import java.util.ArrayList;

public class Lexer {
    int lineInd;
    int pt;
    int lenFile;
    char curChar;
    ArrayList<Token> tokenList;
    StringBuffer buffer;

    public void nextChar() {
        if(curChar == '\n') {
            lineInd++;
        }
        if(!haveNextChar()) {
            this.curChar = '\0';
            pt++;
            return;
        }
        pt++;
        this.curChar = buffer.charAt(pt);
    }

    public boolean haveNextChar() {
        return pt + 1 < lenFile;
    }

    public boolean isEOF() {
        return pt >=lenFile;
    }

    public Token checkResToken(String str) {
        if(str.equals("main"))     return new Token(TokenType.MAINTK,    "main");
        if(str.equals("const"))    return new Token(TokenType.CONSTTK,   "const");
        if(str.equals("int"))      return new Token(TokenType.INTTK,     "int");
        if(str.equals("char"))     return new Token(TokenType.CHARTK,    "char");
        if(str.equals("break"))    return new Token(TokenType.BREAKTK,   "break");
        if(str.equals("continue")) return new Token(TokenType.CONTINUETK,"continue");
        if(str.equals("if"))       return new Token(TokenType.IFTK,      "if");
        if(str.equals("else"))     return new Token(TokenType.ELSETK,    "else");
        if(str.equals("for"))      return new Token(TokenType.FORTK,     "for");
        if(str.equals("getint"))   return new Token(TokenType.GETINTTK,  "getint");
        if(str.equals("getchar"))  return new Token(TokenType.GETCHARTK, "getchar");
        if(str.equals("printf"))   return new Token(TokenType.PRINTFTK,  "printf");
        if(str.equals("return"))   return new Token(TokenType.RETURNTK,  "return");
        if(str.equals("void"))     return new Token(TokenType.VOIDTK,    "void");
        return null;
    }

    public void doLexer() {
        while(!isEOF()) {
//            System.out.print(curChar);
            if (curChar == ' ' || curChar == '\t' || curChar == '\n') {
                nextChar();
                continue;
            } else if (Character.isLetter(curChar) || curChar == '_') {
                StringBuffer curToken = new StringBuffer();
                curToken.append(curChar);
                while(haveNextChar()) {
                    nextChar();
//                    System.out.println(curChar);
                    if(Character.isDigit(curChar) || Character.isLetter(curChar) || curChar == '_') {
                        curToken.append(curChar);
                    } else {
                        break;
                    }
                }
                Token token = checkResToken(curToken.toString());
                if(token != null) {
                    tokenList.add(token);
                } else {
                    tokenList.add(new Token(TokenType.IDENFR, curToken.toString()));
                }
                continue;
            } else if (Character.isDigit(curChar)) {
                StringBuffer curToken = new StringBuffer();
                curToken.append(curChar);
                while(haveNextChar()) {
                    nextChar();
                    if(Character.isDigit(curChar)) {
                        curToken.append(curChar);
                    } else {
                        break;
                    }
                }
                tokenList.add(new Token(TokenType.INTCON, curToken.toString()));
                continue;
            } else if (curChar == '"') {
                StringBuffer curToken = new StringBuffer();
                curToken.append(curChar);
                while(haveNextChar()) {
                    nextChar();
                    if(curChar != '"') {
                        curToken.append(curChar);
                    } else {
                        break;
                    }
                }
                curToken.append(curChar);
                if(haveNextChar()) nextChar();
                tokenList.add(new Token(TokenType.STRCON, curToken.toString()));
                continue;
            } else if (curChar == '\'') {
                StringBuffer curToken = new StringBuffer();
                curToken.append(curChar);
                while(haveNextChar()) {
                    nextChar();
                    if(curChar != '\'') {
                        curToken.append(curChar);
                    } else {
                        break;
                    }
                }
                curToken.append(curChar);
                if(haveNextChar()) nextChar();
                tokenList.add(new Token(TokenType.CHRCON, curToken.toString()));
                continue;
            } else if (curChar == '/') {
                if(haveNextChar()) { nextChar(); }
                if (curChar == '*') {
                    while(haveNextChar()) {
                        nextChar();
                        if(curChar == '*') {
                            if(haveNextChar()) nextChar();
                            if(curChar == '/') {
                                break;
                            }
                        }
                    }
                    if(haveNextChar()) { nextChar();}
                } else if (curChar == '/'){
                    while(haveNextChar() && curChar != '\n') { nextChar(); }
                } else {
                    tokenList.add(new Token(TokenType.DIV, "/"));
                }
                continue;
            } else if (curChar == '&') {
                if(haveNextChar()) nextChar();
                else {
                    System.err.println(lineInd + "a ");
                    tokenList.add(new Token(TokenType.AND, "&&"));
                    continue;
                }
                if(curChar != '&') {
                    System.err.println(lineInd + "a ");
                    tokenList.add(new Token(TokenType.AND, "&&"));
                } else {
                    if(haveNextChar()) nextChar();
                    tokenList.add(new Token(TokenType.AND, "&&"));
                }
                continue;
            } else if (curChar == '|') {
                if(haveNextChar()) nextChar();
                else {
                    System.err.println(lineInd + "a ");
                    tokenList.add(new Token(TokenType.OR, "||"));
                    continue;
                }
                if(curChar != '|') {
                    System.err.println(lineInd + "a ");
                    tokenList.add(new Token(TokenType.OR, "||"));
                } else {
                    if(haveNextChar()) nextChar();
                    tokenList.add(new Token(TokenType.OR, "||"));
                }
                continue;
            } else if (curChar == '+') {
                tokenList.add(new Token(TokenType.PLUS, "+"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '-') {
                tokenList.add(new Token(TokenType.MINU, "-"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '*') {
                tokenList.add(new Token(TokenType.MULT, "*"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '%') {
                tokenList.add(new Token(TokenType.MOD, "%"));
                if(haveNextChar()) nextChar();
            } else if (curChar == ';') {
                tokenList.add(new Token(TokenType.SEMICN, ";"));
                if(haveNextChar()) nextChar();
            } else if (curChar == ',') {
                tokenList.add(new Token(TokenType.COMMA, ","));
                if(haveNextChar()) nextChar();
            } else if (curChar == '(') {
                tokenList.add(new Token(TokenType.LPARENT, "("));
                if(haveNextChar()) nextChar();
            } else if (curChar == ')') {
                tokenList.add(new Token(TokenType.RPARENT, ")"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '[') {
                tokenList.add(new Token(TokenType.LBRACK, "["));
                if(haveNextChar()) nextChar();
            } else if (curChar == ']') {
                tokenList.add(new Token(TokenType.RBRACK, "]"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '{') {
                tokenList.add(new Token(TokenType.LBRACE, "{"));
                if(haveNextChar()) nextChar();
            } else if (curChar == '}') {
                tokenList.add(new Token(TokenType.RBRACE, "}"));
                if(haveNextChar()) nextChar();
            }
            else if (curChar == '!') {
                if (haveNextChar()) nextChar();
                else {
                    tokenList.add(new Token(TokenType.NOT, "!"));
                    continue;
                }
                if(curChar == '=') {
                    tokenList.add(new Token(TokenType.NEQ, "!="));
                    if (haveNextChar()) nextChar();
                } else {
                    tokenList.add(new Token(TokenType.NOT, "!"));
                }
                continue;
            } else if (curChar == '>') {
                if (haveNextChar()) nextChar();
                else {
                    tokenList.add(new Token(TokenType.GRE, ">"));
                    continue;
                }
                if(curChar == '=') {
                    tokenList.add(new Token(TokenType.GEQ, ">="));
                    if (haveNextChar()) nextChar();
                } else {
                    tokenList.add(new Token(TokenType.GRE, ">"));
                }
                continue;
            } else if (curChar == '<') {
                if (haveNextChar()) nextChar();
                else {
                    tokenList.add(new Token(TokenType.LSS, "<"));
                    continue;
                }
                if(curChar == '=') {
                    tokenList.add(new Token(TokenType.LEQ, "<="));
                    if (haveNextChar()) nextChar();
                } else {
                    tokenList.add(new Token(TokenType.LSS, "<"));
                }
                continue;
            } else if (curChar == '=') {
                if (haveNextChar()) nextChar();
                else {
                    tokenList.add(new Token(TokenType.ASSIGN, "="));
                    continue;
                }
                if(curChar == '=') {
                    tokenList.add(new Token(TokenType.EQL, "=="));
                    if (haveNextChar()) nextChar();
                } else {
                    tokenList.add(new Token(TokenType.ASSIGN, "="));
                }
                continue;
            }
        }
    }

    public Lexer(StringBuffer buffer) {
        this.lineInd = 1;
        this.tokenList = new ArrayList<>();
        this.buffer = buffer;
        this.pt = 0;
        this.lenFile = buffer.length();
        this.curChar = buffer.charAt(pt);

        this.doLexer();
        this.print();
    }

    public void print() {
        for(int i = 0;i < this.tokenList.size();i++) {
            tokenList.get(i).print();
        }
    }
}
