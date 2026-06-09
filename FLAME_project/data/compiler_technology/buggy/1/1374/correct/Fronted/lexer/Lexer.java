package Fronted.lexer;

import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

import Error.ErrorList;
import Error.ErrorType;
import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class Lexer {
    private static int curPos;
    private static String token;
    private static final HashMap<String, LexerType> type = new HashMap<>();
    private static TokenList tokenList;
    private static ErrorList errorList;
    private static int flag = 0;
    private static int wrong = 0;

    public Lexer() throws IOException {
        this.setType();
        this.tokenList = TokenList.getTokenList();
        this.errorList = ErrorList.getErrorList();
    }

    public void setType() {
        type.put("Ident",LexerType.IDENFR);
        type.put("IntConst",LexerType.INTCON);
        type.put("StringConst",LexerType.STRCON);
        type.put("CharConst",LexerType.CHRCON);
        type.put("main",LexerType.MAINTK);
        type.put("const", LexerType.CONSTTK);
        type.put("int", LexerType.INTTK);
        type.put("char",LexerType.CHARTK);
        type.put("break", LexerType.BREAKTK);
        type.put("continue", LexerType.CONTINUETK);
        type.put("if", LexerType.IFTK);
        type.put("else", LexerType.ELSETK);
        type.put("!", LexerType.NOT);
        type.put("&&", LexerType.AND);
        type.put("||", LexerType.OR);
        type.put("for", LexerType.FORTK);
        type.put("getint", LexerType.GETINTTK);
        type.put("getchar", LexerType.GETCHARTK);
        type.put("printf", LexerType.PRINTFTK);
        type.put("return", LexerType.RETURNTK);
        type.put("+", LexerType.PLUS);
        type.put("-", LexerType.MINU);
        type.put("void", LexerType.VOIDTK);
        type.put("*", LexerType.MULT);
        type.put("/", LexerType.DIV);
        type.put("%", LexerType.MOD);
        type.put("<", LexerType.LSS);
        type.put("<=", LexerType.LEQ);
        type.put(">", LexerType.GRE);
        type.put(">=", LexerType.GEQ);
        type.put("==", LexerType.EQL);
        type.put("!=", LexerType.NEQ);
        type.put("=", LexerType.ASSIGN);
        type.put(";", LexerType.SEMICN);
        type.put(",", LexerType.COMMA);
        type.put("(", LexerType.LPARENT);
        type.put(")", LexerType.RPARENT);
        type.put("[", LexerType.LBRACK);
        type.put("]", LexerType.RBRACK);
        type.put("{", LexerType.LBRACE);
        type.put("}", LexerType.RBRACE);
    }

    public static void divide(String line, int lineNumber) throws IOException {
        curPos = 0;
        token = "";
        if (flag == 1) {
            for (int c = 0; c < line.length(); c++) {
                if (line.charAt(c) == '*' && line.charAt(c + 1) == '/') {
                    curPos = c + 2 ;
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0) {
            while (curPos < line.length()) {

                if (isLetter(line.charAt(curPos)) || line.charAt(curPos) == '_') {
                    token += line.charAt(curPos);
                    curPos++;
                    while(curPos < line.length() &&
                            (isLetter(line.charAt(curPos)) || Character.isDigit(line.charAt(curPos)) || line.charAt(curPos) == '_')) {
                        token += line.charAt(curPos);
                        curPos++;
                    }
                    lookFor(token, lineNumber);
                    token = "";
                } else if (isDigit(line.charAt(curPos))){
                    while(isDigit(line.charAt(curPos))) {
                        token += line.charAt(curPos);
                        curPos++;
                    }
                    BigInteger num = BigInteger.valueOf(Long.parseLong(token));
                    //System.out.println(num);
                    //outputInt(num, LexerType.INTCON);
                    addToken(token, LexerType.INTCON, lineNumber, num);
                    token = "";
                } else if (line.charAt(curPos) == ' ' || line.charAt(curPos) == '\t') {
                    curPos++;
                } else if (line.charAt(curPos) == '&' || line.charAt(curPos) == '|') {
                    if (line.charAt(curPos) == '&') {
                        token += line.charAt(curPos);
                        curPos++;
                        if (line.charAt(curPos) == '&') {
                            token += line.charAt(curPos);
                            lookFor(token, lineNumber);
                            curPos++;
                            token = "";
                        } else {
                            //outputWrong(token,lineNumber);
                            //ErrorList.getErrorList().add(lineNumber, ErrorType.a);
                            addError(lineNumber);
                            token += line.charAt(curPos - 1);
                            lookFor(token, lineNumber);
                            curPos++;
                            token = "";
                        }
                    } else if (line.charAt(curPos) == '|') {
                        token += line.charAt(curPos);
                        curPos++;
                        if (line.charAt(curPos) == '|') {
                            token += line.charAt(curPos);
                            lookFor(token, lineNumber);
                            curPos++;
                            token = "";
                        } else {
                            //outputWrong(token,lineNumber);
                            addError(lineNumber);
                            //ErrorList.getErrorList().add(lineNumber, ErrorType.a);
                            token += line.charAt(curPos - 1);
                            lookFor(token, lineNumber);
                            curPos++;
                            token = "";
                        }
                    }
                } else if (line.charAt(curPos) == '/') {
                    if (curPos + 1 < line.length() && line.charAt(curPos + 1) == '/') {
                        break;
                    } else if (curPos + 1 < line.length() && line.charAt(curPos + 1) == '*') {
                        int flag1 = 0;
                        for (int i = curPos + 2; i < line.length(); i++) {
                            if (line.charAt(i) == '*' && line.charAt(i + 1) == '/') {
                                curPos = i + 2;
                                flag1 = 1;
                                break;
                            }
                        }
                        if (flag1 == 1) {
                            flag = 0;
                        } else {
                            flag = 1;
                        }
                        break;
                    } else {
                        token += line.charAt(curPos);
                        curPos++;
                        lookFor(token, lineNumber);
                        token = "";
                    }
                } else if (line.charAt(curPos) == '!' || line.charAt(curPos) == '<'
                        || line.charAt(curPos) == '>' || line.charAt(curPos) == '=') {
                    token += line.charAt(curPos);
                    curPos++;
                    if (line.charAt(curPos) == '=') {
                        token += line.charAt(curPos);
                        curPos++;
                        lookFor(token, lineNumber);
                        token = "";
                    } else {
                        lookFor(token, lineNumber);
                        token = "";
                    }
                } else if (line.charAt(curPos) == '\"') {
                    token += line.charAt(curPos);
                    curPos++;
                /*while(token.charAt(curPos) != '\"') {
                    token1 += token.charAt(curPos);
                    curPos++;
                }*/
                    for (int i = curPos; i < line.length(); i++) {
                        token += line.charAt(i);
                        if (line.charAt(i) == '\"') {
                            curPos = i + 1;
                            break;
                        }
                    }
                    //output(token, LexerType.STRCON);
                    addToken(token, LexerType.STRCON, lineNumber, BigInteger.valueOf(0));
                    token = "";
                } else if (line.charAt(curPos) == '\'') {
                    token += line.charAt(curPos);
                    curPos++;
                /*while(token.charAt(curPos) != '\'') {
                    token1 += token.charAt(curPos);
                    curPos++;
                }*/
                    for (int i = curPos; i < line.length(); i++) {
                        token += line.charAt(i);
                        if (line.charAt(i) == '\\' && line.charAt(i + 1) == '\'') {
                            i++;
                            token += line.charAt(i);
                        } else if (line.charAt(i) == '\'') {
                            curPos = i + 1;
                            break;
                        }
                    }
                    //output(token, LexerType.CHRCON);
                    addToken(token, LexerType.CHRCON, lineNumber, BigInteger.valueOf(0));
                    token = "";
                } else {
                    String c = String.valueOf(line.charAt(curPos));
                    lookFor(c, lineNumber);
                    curPos++;
                    token = "";
                }
            }
        }
    }

    public static void addToken(String token, LexerType type, int lineNumber, BigInteger num) {
        tokenList.add(new Token(token, type, lineNumber, num));
    }

    public static void lookFor(String token, int lineNumber) {
        addToken(token, type.getOrDefault(token, LexerType.IDENFR), lineNumber, BigInteger.valueOf(0));
    }

    public static void addError(int lineNumber) {
        errorList.add(lineNumber, ErrorType.a);
    }


    /*
    public static void lookFor(String token) throws IOException {
        output(token, type.getOrDefault(token, LexerType.IDENFR));
    }

    public static void output(String token, String type) throws IOException {
        //System.out.println(type + " " + token);
        right.write(type + " " + token + "\n");
    }

    public static void outputWrong(String token, int lineNumber) throws IOException {
        //System.out.println(lineNumber + " " + token);
        error.write(lineNumber + " " + "a" + "\n");
        wrong = 0;
    }

    public static void outputInt(BigInteger num, String type) throws IOException {
        //System.out.println(type + " " + num);
        right.write(type + " " + token + "\n");
    }*/
}
