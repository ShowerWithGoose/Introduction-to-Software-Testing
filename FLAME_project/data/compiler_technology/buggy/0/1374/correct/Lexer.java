import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;

import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class Lexer {

    private static int curPos;
    private static String token;
    private static final HashMap<String, String> type = new HashMap<>();
    private static int flag = 0;
    private static int wrong = 0;


    public Lexer() throws IOException {
        this.setType();
        //this.linesMap = linesMap;
    }

    static FileWriter fw1;

    static {
        try {
            fw1 = new FileWriter(new File("lexer.txt"));
            //fw1 = new FileWriter(new File("D:\\idea projects\\CiFaFenXi\\lexer.txt"));


        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static FileWriter fw2;

    static {
        try {
            fw2 = new FileWriter(new File("error.txt"));
            //fw2 = new FileWriter(new File("D:\\idea projects\\CiFaFenXi\\error.txt"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static BufferedWriter right= new BufferedWriter(fw1);
    static BufferedWriter error= new BufferedWriter(fw2);

    public void setType() {
        type.put("Ident","IDENFR");
        type.put("IntConst","INTCON");
        type.put("StringConst","STRCON");
        type.put("CharConst","CHARCON");
        type.put("main","MAINTK");
        type.put("const", "CONSTTK");
        type.put("int", "INTTK");
        type.put("char","CHARTK");
        type.put("break", "BREAKTK");
        type.put("continue", "CONTINUETK");
        type.put("if", "IFTK");
        type.put("else", "ELSETK");
        type.put("!", "NOT");
        type.put("&&", "AND");
        type.put("||", "OR");
        type.put("for", "FORTK");
        type.put("getint", "GETINTTK");
        type.put("getchar", "GETCHARTK");
        type.put("printf", "PRINTFTK");
        type.put("return", "RETURNTK");
        type.put("+", "PLUS");
        type.put("-", "MINU");
        type.put("void", "VOIDTK");
        type.put("*", "MULT");
        type.put("/", "DIV");
        type.put("%", "MOD");
        type.put("<", "LSS");
        type.put("<=", "LEQ");
        type.put(">", "GRE");
        type.put(">=", "GEQ");
        type.put("==", "EQL");
        type.put("!=", "NEQ");
        type.put("=", "ASSIGN");
        type.put(";", "SEMICN");
        type.put(",", "COMMA");
        type.put("(", "LPARENT");
        type.put(")", "RPARENT");
        type.put("[", "LBRACK");
        type.put("]", "RBRACK");
        type.put("{", "LBRACE");
        type.put("}", "RBRACE");
    }

    public static boolean isNonDigit(char a) {
        return !isDigit(a);
    }

    public  void analyze(String line, int lineNumber) throws IOException {
        divide(line, lineNumber);
        /*curPos = 0;
        token = "";
        while (curPos < line.length()) {
            if (flag == 1) {
                for (int c = 0; c < line.length(); c++) {
                    if (line.charAt(c) == '*' && line.charAt(c + 1) == '/') {
                        curPos = c + 2 ;
                        break;
                    }
                }
                flag = 0;
            }
            if (isNonDigit(line.charAt(curPos))) {
                token += line.charAt(curPos);
                curPos++;
                while(curPos < line.length() && (isNonDigit(line.charAt(curPos))
                        || (Character.isDigit(line.charAt(curPos)) && isLetter(line.charAt(curPos - 1)))
                || (Character.isDigit(line.charAt(curPos)) && line.charAt(curPos - 1) == '\"'))) {
                    token += line.charAt(curPos);
                    curPos++;
                }
                //System.out.println(token);
                divide(token, lineNumber);
                //System.out.println(token + " " + lineNumber);
                token = "";
            } else if (isDigit(line.charAt(curPos))) {
                while(isDigit(line.charAt(curPos))) {
                    token += line.charAt(curPos);
                    curPos++;
                }
                int num = Integer.parseInt(token);
                //System.out.println(num);
                outputInt(num,"INTCON");
                token = "";
            }
        }*/
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
                    lookFor(token);
                    token = "";
                } else if (isDigit(line.charAt(curPos))){
                    while(isDigit(line.charAt(curPos))) {
                        token += line.charAt(curPos);
                        curPos++;
                    }
                    BigInteger num = BigInteger.valueOf(Long.parseLong(token));
                    //System.out.println(num);
                    outputInt(num,"INTCON");
                    token = "";
                } else if (line.charAt(curPos) == ' ' || line.charAt(curPos) == '\t') {
                    curPos++;
                } else if (line.charAt(curPos) == '&' || line.charAt(curPos) == '|') {
                    if (line.charAt(curPos) == '&') {
                        token += line.charAt(curPos);
                        curPos++;
                        if (line.charAt(curPos) == '&') {
                            token += line.charAt(curPos);
                            lookFor(token);
                            curPos++;
                            token = "";
                        } else {
                            outputWrong(token,lineNumber);
                            wrong = 1;
                            curPos++;
                            token = "";
                        }
                    } else if (line.charAt(curPos) == '|') {
                        token += line.charAt(curPos);
                        curPos++;
                        if (line.charAt(curPos) == '|') {
                            token += line.charAt(curPos);
                            lookFor(token);
                            curPos++;
                            token = "";
                        } else {
                            outputWrong(token,lineNumber);
                            wrong = 1;
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
                        lookFor(token);
                        token = "";
                    }
                } else if (line.charAt(curPos) == '!' || line.charAt(curPos) == '<'
                        || line.charAt(curPos) == '>' || line.charAt(curPos) == '=') {
                    token += line.charAt(curPos);
                    curPos++;
                    if (line.charAt(curPos) == '=') {
                        token += line.charAt(curPos);
                        curPos++;
                        lookFor(token);
                        token = "";
                    } else {
                        lookFor(token);
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
                    output(token,"STRCON");
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
                    output(token,"CHRCON");
                    token = "";
                } else {
                    String c = String.valueOf(line.charAt(curPos));
                    lookFor(c);
                    curPos++;
                    token = "";
                }
            }
        }

    }

    public static void lookFor(String token) throws IOException {
        output(token, type.getOrDefault(token, "IDENFR"));
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
    }
}
