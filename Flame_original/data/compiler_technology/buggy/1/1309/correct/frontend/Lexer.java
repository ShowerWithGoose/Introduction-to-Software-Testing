package frontend;

import java.util.ArrayList;

import static frontend.ErrList.errList;

public class Lexer {
    int lineNum;
    int pt;
    int lenFile;
    char curChar;
    ArrayList<Symbol> symbolList;
    StringBuffer buffer;

    public void nextChar() {
        if(curChar == '\n') {
            lineNum++;
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
        return pt >= lenFile;
    }

    public Symbol checkResToken(String str) {
        if(str.equals("main"))     return new Symbol(SymbolType.MAINTK,    "main"    ,lineNum);
        if(str.equals("const"))    return new Symbol(SymbolType.CONSTTK,   "const"   ,lineNum);
        if(str.equals("int"))      return new Symbol(SymbolType.INTTK,     "int"     ,lineNum);
        if(str.equals("char"))     return new Symbol(SymbolType.CHARTK,    "char"    ,lineNum);
        if(str.equals("break"))    return new Symbol(SymbolType.BREAKTK,   "break"   ,lineNum);
        if(str.equals("continue")) return new Symbol(SymbolType.CONTINUETK,"continue",lineNum);
        if(str.equals("if"))       return new Symbol(SymbolType.IFTK,      "if"      ,lineNum);
        if(str.equals("else"))     return new Symbol(SymbolType.ELSETK,    "else"    ,lineNum);
        if(str.equals("for"))      return new Symbol(SymbolType.FORTK,     "for"     ,lineNum);
        if(str.equals("getint"))   return new Symbol(SymbolType.GETINTTK,  "getint"  ,lineNum);
        if(str.equals("getchar"))  return new Symbol(SymbolType.GETCHARTK, "getchar" ,lineNum);
        if(str.equals("printf"))   return new Symbol(SymbolType.PRINTFTK,  "printf"  ,lineNum);
        if(str.equals("return"))   return new Symbol(SymbolType.RETURNTK,  "return"  ,lineNum);
        if(str.equals("void"))     return new Symbol(SymbolType.VOIDTK,    "void"    ,lineNum);
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
                Symbol symbol = checkResToken(curToken.toString());
                if(symbol != null) {
                    symbolList.add(symbol);
                } else {
                    symbolList.add(new Symbol(SymbolType.IDENFR, curToken.toString() ,lineNum));
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
                symbolList.add(new Symbol(SymbolType.INTCON, curToken.toString() ,lineNum));
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
                symbolList.add(new Symbol(SymbolType.STRCON, curToken.toString() ,lineNum));
                continue;
            } else if (curChar == '\'') {
                StringBuffer curToken = new StringBuffer();
                curToken.append(curChar);
                nextChar();
                if(curChar == '\\') {
                    curToken.append(curChar);
                    nextChar();
                }
                curToken.append(curChar);
                nextChar();
                curToken.append(curChar);
                if(haveNextChar()) nextChar();
                symbolList.add(new Symbol(SymbolType.CHRCON, curToken.toString() ,lineNum));
                continue;
            } else if (curChar == '/') {
                if(haveNextChar()) { nextChar(); }
                if (curChar == '*') {
                    nextChar();
                    while(haveNextChar()) {
                        if(curChar == '*') {
                            if(haveNextChar()) nextChar();
                            if(curChar == '/') {
                                break;
                            }
                        } else {
                            if(haveNextChar()) nextChar();
                        }
                    }
                    if(haveNextChar()) { nextChar();}
                } else if (curChar == '/'){
                    while(haveNextChar() && curChar != '\n') { nextChar(); }
                } else {
                    symbolList.add(new Symbol(SymbolType.DIV, "/" ,lineNum));
                }
                continue;
            } else if (curChar == '&') {
                if(haveNextChar()) nextChar();
                else {
                    errList.add(new ErrInfo(lineNum, 'a'));
                    symbolList.add(new Symbol(SymbolType.AND, "&&" ,lineNum));
                    continue;
                }
                if(curChar != '&') {
                    errList.add(new ErrInfo(lineNum, 'a'));
                    symbolList.add(new Symbol(SymbolType.AND, "&&" ,lineNum));
                } else {
                    if(haveNextChar()) nextChar();
                    symbolList.add(new Symbol(SymbolType.AND, "&&" ,lineNum));
                }
                continue;
            } else if (curChar == '|') {
                if(haveNextChar()) nextChar();
                else {
                    errList.add(new ErrInfo(lineNum, 'a'));
                    symbolList.add(new Symbol(SymbolType.OR, "||" ,lineNum ));
                    continue;
                }
                if(curChar != '|') {
                    errList.add(new ErrInfo(lineNum, 'a'));
                    symbolList.add(new Symbol(SymbolType.OR, "||" ,lineNum));
                } else {
                    if(haveNextChar()) nextChar();
                    symbolList.add(new Symbol(SymbolType.OR, "||" ,lineNum));
                }
                continue;
            } else if (curChar == '+') {
                symbolList.add(new Symbol(SymbolType.PLUS, "+", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '-') {
                symbolList.add(new Symbol(SymbolType.MINU, "-", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '*') {
                symbolList.add(new Symbol(SymbolType.MULT, "*", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '%') {
                symbolList.add(new Symbol(SymbolType.MOD, "%", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == ';') {
                symbolList.add(new Symbol(SymbolType.SEMICN, ";", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == ',') {
                symbolList.add(new Symbol(SymbolType.COMMA, ",", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '(') {
                symbolList.add(new Symbol(SymbolType.LPARENT, "(", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == ')') {
                symbolList.add(new Symbol(SymbolType.RPARENT, ")", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '[') {
                symbolList.add(new Symbol(SymbolType.LBRACK, "[", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == ']') {
                symbolList.add(new Symbol(SymbolType.RBRACK, "]", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '{') {
                symbolList.add(new Symbol(SymbolType.LBRACE, "{", lineNum));
                if(haveNextChar()) nextChar();
            } else if (curChar == '}') {
                symbolList.add(new Symbol(SymbolType.RBRACE, "}", lineNum));
                if(haveNextChar()) nextChar();
            }
            else if (curChar == '!') {
                if (haveNextChar()) nextChar();
                else {
                    symbolList.add(new Symbol(SymbolType.NOT, "!", lineNum));
                    continue;
                }
                if(curChar == '=') {
                    symbolList.add(new Symbol(SymbolType.NEQ, "!=", lineNum));
                    if (haveNextChar()) nextChar();
                } else {
                    symbolList.add(new Symbol(SymbolType.NOT, "!", lineNum));
                }
                continue;
            } else if (curChar == '>') {
                if (haveNextChar()) nextChar();
                else {
                    symbolList.add(new Symbol(SymbolType.GRE, ">", lineNum));
                    continue;
                }
                if(curChar == '=') {
                    symbolList.add(new Symbol(SymbolType.GEQ, ">=", lineNum));
                    if (haveNextChar()) nextChar();
                } else {
                    symbolList.add(new Symbol(SymbolType.GRE, ">", lineNum));
                }
                continue;
            } else if (curChar == '<') {
                if (haveNextChar()) nextChar();
                else {
                    symbolList.add(new Symbol(SymbolType.LSS, "<", lineNum));
                    continue;
                }
                if(curChar == '=') {
                    symbolList.add(new Symbol(SymbolType.LEQ, "<=", lineNum));
                    if (haveNextChar()) nextChar();
                } else {
                    symbolList.add(new Symbol(SymbolType.LSS, "<", lineNum));
                }
                continue;
            } else if (curChar == '=') {
                if (haveNextChar()) nextChar();
                else {
                    symbolList.add(new Symbol(SymbolType.ASSIGN, "=", lineNum));
                    continue;
                }
                if(curChar == '=') {
                    symbolList.add(new Symbol(SymbolType.EQL, "==", lineNum));
                    if (haveNextChar()) nextChar();
                } else {
                    symbolList.add(new Symbol(SymbolType.ASSIGN, "=", lineNum));
                }
                continue;
            }
        }
    }

    public Lexer(StringBuffer buffer) {
        this.lineNum = 1;
        this.symbolList = new ArrayList<>();
        this.buffer = buffer;
        this.pt = 0;
        this.lenFile = buffer.length();
        this.curChar = buffer.charAt(pt);

        this.doLexer();
//        this.print();
    }

    public void print() {
        for(int i = 0; i < this.symbolList.size(); i++) {
            symbolList.get(i).print();
        }
    }

    public ArrayList<Symbol> getSymbolList() {
        return this.symbolList;
    }
}
