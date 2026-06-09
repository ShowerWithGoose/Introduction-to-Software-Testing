package frontend;

import java.util.HashMap;

public class PreLexer {
    private static PreLexer prelexer = new PreLexer();
    private static String input;
    private static Token token;
    private static char c;
    private static HashMap<String, Type> reserves;
    private static int pos;

    public PreLexer() {
        token = new Token();
        reserves = new HashMap<String, Type>() {
            {
                put("main", Type.MAINTK);
                put("const", Type.CONSTTK);
                put("int", Type.INTTK);
                put("char", Type.CHARTK);
                put("break", Type.BREAKTK);
                put("continue", Type.CONTINUETK);
                put("if", Type.IFTK);
                put("else", Type.ELSETK);
                put("for", Type.FORTK);
                put("getint", Type.GETINTTK);
                put("getchar", Type.GETCHARTK);
                put("printf", Type.PRINTFTK);
                put("return", Type.RETURNTK);
                put("void", Type.VOIDTK);
            }
        };
        pos = 0;
    }

    public static Token getSym(boolean isContinuous) {
        if(!isContinuous) pos = Lexer.getPos();
        if (pos >= input.length()) return new Token(Type.NULL);
        clearToken();
        getChar();
        while (isWhite()) {   //去空白字符
            getChar();
        }
        if (isLetter()) {     //处理标识符、保留字
            while (isLetter() || isDigital()) {
                catToken();
                getChar();
            }
            retract();
            token.enType(reserve());
            return token;
        } else if (isDigital()) {  //处理整型常量
            while (isDigital()) {
                catToken();
                getChar();
            }
            retract();
            //token.enNum(transNum());
            token.enType(Type.INTCON);
            return token;
        } else if (c == '\'') {  //处理字符常量
            catToken();
            getChar();
            if (c == '\'') {    //空字符错误''
                //error('\0');
            } else {            //非空
                if(c=='\\'){    //转义字符'\~'
                    catToken();
                    getChar();
                    catToken();
                    getChar();
                }else{          //非转义字符'~'
                    catToken();
                    getChar();
                }
                if(c!='\''){    //缺失后单引号错误
                    //error('\0');
                }
                catToken();
                token.enType(Type.CHRCON);
                return token;
            }
        } else if (c == '\"') {  //处理字符串常量
            catToken();
            getChar();
            while (c != '\"') {
                catToken();
                getChar();
            }
            catToken();
            token.enType(Type.STRCON);
            return token;
        } else if (c == '!') {   //处理!=、!
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.NEQ);
            } else {
                retract();
                token.enType(Type.NOT);
            }
            return token;
        } else if (c == '&') {   //处理&&
            catToken();
            getChar();
            token.enType(Type.AND);
            if (c != '&') {
                token.append('&');
                //error('a');
                retract();
            } else {
                catToken();
            }
            return token;
        } else if (c == '|') {   //处理||
            catToken();
            getChar();
            token.enType(Type.OR);
            if (c != '|') {
                token.append('|');
                //error('a');
                retract();
            } else {
                catToken();
            }
            return token;
        } else if (c == '+') {
            catToken();
            token.enType(Type.PLUS);
            return token;
        } else if (c == '-') {
            catToken();
            token.enType(Type.MINU);
            return token;
        } else if (c == '*') {
            catToken();
            token.enType(Type.MULT);
            return token;
        } else if (c == '/') {
            catToken();
            getChar();
            if (c == '*') {  //处理/**/
                while (true) {
                    do {
                        getChar();
                    } while (c != '*');
                    do {
                        getChar();
                        if (c == '/') return getSym(true);
                    } while (c == '*');
                }
            } else if (c == '/') {
                do {
                    getChar();
                } while (c != '\n');
                return getSym(true);
            } else {
                retract();
                token.enType(Type.DIV);
                return token;
            }
        } else if (c == '%') {
            catToken();
            token.enType(Type.MOD);
            return token;
        } else if (c == '<') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.LEQ);
            } else {
                retract();
                token.enType(Type.LSS);
            }
            return token;
        } else if (c == '>') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.GEQ);
            } else {
                retract();
                token.enType(Type.GRE);
            }
            return token;
        } else if (c == '=') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.EQL);
            } else {
                retract();
                token.enType(Type.ASSIGN);
            }
            return token;
        } else if (c == ';') {
            catToken();
            token.enType(Type.SEMICN);
            return token;
        } else if (c == ',') {
            catToken();
            token.enType(Type.COMMA);
            return token;
        } else if (c == '(') {
            catToken();
            token.enType(Type.LPARENT);
            return token;
        } else if (c == ')') {
            catToken();
            token.enType(Type.RPARENT);
            return token;
        } else if (c == '[') {
            catToken();
            token.enType(Type.LBRACK);
            return token;
        } else if (c == ']') {
            catToken();
            token.enType(Type.RBRACK);
            return token;
        } else if (c == '{') {
            catToken();
            token.enType(Type.LBRACE);
            return token;
        } else if (c == '}') {
            catToken();
            token.enType(Type.RBRACE);
            return token;
        } else {
            //error('\0');
        }
        return new Token(Type.NULL);
    }

    private static void getChar() {
        if (pos >= input.length()) {
            c = 0;
            pos++;
        } else {
            c = input.charAt(pos++);
        }
    }
    private static void retract() {
        pos--;
    }

    private static boolean isWhite() {
        return c == ' ' || c == '\n' || c == '\t';
    }

    private static boolean isLetter() {
        return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 95);
    }

    private static boolean isDigital() {
        return c >= '0' && c <= '9';
    }

    private static void catToken() {
        token.append(c);
    }

    private static Type reserve() {
        return reserves.getOrDefault(token.getName(), Type.IDENFR);
    }

    private static int transNum() {
        return Integer.parseInt(token.getName());
    }

    private static void clearToken() {
        token = new Token();
    }

    public static PreLexer getInstance() {
        return prelexer;
    }

    public static void Input(String input) {
        PreLexer.input = input;
    }
    public static void movePointer(int count){
        pos-=count;
    }
}
