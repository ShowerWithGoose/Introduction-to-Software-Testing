package frontend;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Objects;

public class Lexer {
    private static Lexer lexer = new Lexer();
    private static String input;
    private static Token token;
    private static char c;
    private static HashMap<String, Type> reserves;
    private static int pos;
    private static int line;
    private static LinkedList<Token> tokenList;
    private static LinkedList<String> errorList;
    private static PrintStream fileOut1;
    private static PrintStream fileOut2;

    public Lexer() {
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
        line = 1;
        tokenList = new LinkedList<>();
        errorList = new LinkedList<>();
        pos = 0;
        try {
            fileOut1 = new PrintStream("parser.txt");
            fileOut2 = new PrintStream("error.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static Token getSym() {
        if (pos >= input.length()) {
            token.enType(Type.NULL);
            list();
            return token;
        }
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
            list();
            return token;
        } else if (isDigital()) {  //处理整型常量
            while (isDigital()) {
                catToken();
                getChar();
            }
            retract();
            //token.enNum(transNum());
            token.enType(Type.INTCON);
            list();
            return token;
        } else if (c == '\'') {  //处理字符常量
            catToken();
            getChar();
            if (c == '\'') {    //空字符错误''
                error('\0');
            } else {            //非空
                if (c == '\\') {    //转义字符'\~'
                    catToken();
                    getChar();
                    catToken();
                    getChar();
                } else {          //非转义字符'~'
                    catToken();
                    getChar();
                }
                if (c != '\'') {    //缺失后单引号错误
                    error('\0');
                }
                catToken();
                token.enType(Type.CHRCON);
                list();
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
            list();
            return token;
        } else if (c == '!') {   //处理!=、!
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.NEQ);
                list();
            } else {
                retract();
                token.enType(Type.NOT);
                list();
            }
            return token;
        } else if (c == '&') {   //处理&&
            catToken();
            getChar();
            token.enType(Type.AND);
            if (c != '&') {
                list();
                error('a');
                retract();
            } else {
                catToken();
                list();
            }
            return token;
        } else if (c == '|') {   //处理||
            catToken();
            getChar();
            token.enType(Type.OR);
            if (c != '|') {
                list();
                error('a');
                retract();
            } else {
                catToken();
                list();
            }
            return token;
        } else if (c == '+') {
            catToken();
            token.enType(Type.PLUS);
            list();
            return token;
        } else if (c == '-') {
            catToken();
            token.enType(Type.MINU);
            list();
            return token;
        } else if (c == '*') {
            catToken();
            token.enType(Type.MULT);
            list();
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
                        if (c == '/') return getSym();
                    } while (c == '*');
                }
            } else if (c == '/') {
                do {
                    getChar();
                } while (c != '\n');
                return getSym();
            } else {
                retract();
                token.enType(Type.DIV);
                list();
                return token;
            }
        } else if (c == '%') {
            catToken();
            token.enType(Type.MOD);
            list();
            return token;
        } else if (c == '<') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.LEQ);
                list();
            } else {
                retract();
                token.enType(Type.LSS);
                list();
            }
            return token;
        } else if (c == '>') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.GEQ);
                list();
            } else {
                retract();
                token.enType(Type.GRE);
                list();
            }
            return token;
        } else if (c == '=') {
            catToken();
            getChar();
            if (c == '=') {
                catToken();
                token.enType(Type.EQL);
                list();
            } else {
                retract();
                token.enType(Type.ASSIGN);
                list();
            }
            return token;
        } else if (c == ';') {
            catToken();
            token.enType(Type.SEMICN);
            list();
            return token;
        } else if (c == ',') {
            catToken();
            token.enType(Type.COMMA);
            list();
            return token;
        } else if (c == '(') {
            catToken();
            token.enType(Type.LPARENT);
            list();
            return token;
        } else if (c == ')') {
            catToken();
            token.enType(Type.RPARENT);
            list();
            return token;
        } else if (c == '[') {
            catToken();
            token.enType(Type.LBRACK);
            list();
            return token;
        } else if (c == ']') {
            catToken();
            token.enType(Type.RBRACK);
            list();
            return token;
        } else if (c == '{') {
            catToken();
            token.enType(Type.LBRACE);
            list();
            return token;
        } else if (c == '}') {
            catToken();
            token.enType(Type.RBRACE);
            list();
            return token;
        } else {
            error('\0');
        }
        token.enType(Type.INTCON);
        list();
        return token;
    }

    private static void getChar() {
        if (c == '\n') line++;
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

    private static void error(char c) {
        switch (c) {
            case 'a':
                fileOut2.printf("%d %c\n", line, 'a');
                Token t = token;
                token = new Token();
                token.clone(t);
                if (Objects.equals(token.getName(), "&")) {
                    token.append('&');
                } else if (Objects.equals(token.getName(), "|")) {
                    token.append('|');
                }
                break;
            default:
                break;
        }
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

    public static Lexer getInstance() {
        return lexer;
    }

    public static void Input(String input) {
        Lexer.input = input;
    }

    public static int getPos() {
        return pos;
    }

    public static int getLine() {
        return line;
    }

    public static void setFile(PrintStream fileOut1, PrintStream fileOut2) {
        Lexer.fileOut1 = fileOut1;
        Lexer.fileOut2 = fileOut2;
    }

    private static void list() {
        tokenList.addLast(token);
    }
    public static void print(){
        int count = 0;
        Iterator<Token> iterator = tokenList.iterator();
        while (iterator.hasNext()) {
            Token t = iterator.next();
            if(count < tokenList.size() - 1){
                fileOut1.printf("%s %s\n",t.getType(),t.getName());
            }
            count++;
        }
        tokenList.subList(0, tokenList.size() - 1).clear();
    }
}
