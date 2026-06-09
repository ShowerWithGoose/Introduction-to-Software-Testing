package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Lexer {
    private final String stream;
    private final ArrayList<Token> tokens;

    public Lexer(String stream) {
        this.stream = stream;
        this.tokens = new ArrayList<>();
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public void run() {
        int i = 0;
        int lineNum = 1;
        //System.out.println(stream.length());
        while (i != stream.length()) {
            while ((i != stream.length()) && (stream.charAt(i) == ' ' || stream.charAt(i) == '\n' || stream.charAt(i) == '\t')) {
                //System.out.println(stream.charAt(i));
                if (stream.charAt(i) == '\n') {
                    lineNum++;
                    //System.out.println("line:" + lineNum);
                }
                i++;
            }
            if (i == stream.length()) {
                break;
            }
            if (stream.charAt(i) == '_' || Character.isLetter(stream.charAt(i))) {//标识符 关键字
                StringBuilder sb = new StringBuilder();
                sb.append(stream.charAt(i));
                i++;
                while ((i != stream.length()) && (Character.isDigit(stream.charAt(i)) || stream.charAt(i) == '_' || Character.isLetter(stream.charAt(i)))) {
                    sb.append(stream.charAt(i));
                    i++;
                }
                String name = sb.toString();
                String type;
                if (name.equals("main")) {
                    type = "MAINTK";
                } else if (name.equals("const")) {
                    type = "CONSTTK";
                } else if (name.equals("int")) {
                    type = "INTTK";
                } else if (name.equals("char")) {
                    type = "CHARTK";
                } else if (name.equals("break")) {
                    type = "BREAKTK";
                } else if (name.equals("continue")) {
                    type = "CONTINUETK";
                } else if (name.equals("if")) {
                    type = "IFTK";
                } else if (name.equals("else")) {
                    type = "ELSETK";
                } else if (name.equals("for")) {
                    type = "FORTK";
                } else if (name.equals("getint")) {
                    type = "GETINTTK";
                } else if (name.equals("getchar")) {
                    type = "GETCHARTK";
                } else if (name.equals("printf")) {
                    type = "PRINTFTK";
                } else if (name.equals("return")) {
                    type = "RETURNTK";
                } else if (name.equals("void")) {
                    type = "VOIDTK";
                } else {
                    type = "IDENFR";
                }
                tokens.add(new Token(name, type));
                /*if (i != stream.length()) {
                    i--;
                }*/
                //System.out.println(name);
            } else if (Character.isDigit(stream.charAt(i))) {
                StringBuilder sb = new StringBuilder();
                sb.append(stream.charAt(i));
                i++;
                while ((i != stream.length()) && (Character.isDigit(stream.charAt(i)))) {
                    sb.append(stream.charAt(i));
                    i++;
                }
                String name = sb.toString();
                tokens.add(new Token(name, "INTCON"));
                /*if (i != stream.length()) {
                    i--;
                }*/
            } else if (stream.charAt(i) == '\"') {
                i++;
                StringBuilder sb = new StringBuilder();
                while ((i != stream.length()) && stream.charAt(i) != '\"') {
                    if(stream.charAt(i)=='\\'){
                        sb.append(stream.charAt(i));
                        i++;
                    }
                    sb.append(stream.charAt(i));
                    i++;
                }
                i++;
                String name = sb.toString();
                tokens.add(new Token('\"' + name + '\"', "STRCON"));
            } else if (stream.charAt(i) == '\'') {
                i++;
                StringBuilder sb = new StringBuilder();
                while ((i != stream.length()) && stream.charAt(i) != '\'') {
                    if(stream.charAt(i)=='\\'){
                        sb.append(stream.charAt(i));
                        i++;
                    }
                    sb.append(stream.charAt(i));
                    i++;
                }
                i++;
                String name = sb.toString();
                tokens.add(new Token('\'' + name + '\'', "CHRCON"));
            } else if (stream.charAt(i) == '!') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '=') {
                    tokens.add(new Token("!", "NOT"));
                } else {
                    tokens.add(new Token("!=", "NEQ"));
                    i++;
                }
            } else if (stream.charAt(i) == '<') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '=') {
                    tokens.add(new Token("<", "LSS"));
                } else {
                    tokens.add(new Token("<=", "LEQ"));
                    i++;
                }
            } else if (stream.charAt(i) == '>') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '=') {
                    tokens.add(new Token(">", "GRE"));
                } else {
                    tokens.add(new Token(">=", "GEQ"));
                    i++;
                }
            } else if (stream.charAt(i) == '=') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '=') {
                    tokens.add(new Token("=", "ASSIGN"));
                } else {
                    tokens.add(new Token("==", "EQL"));
                    i++;
                }
            } else if (stream.charAt(i) == '&') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '&') {
                    printError(lineNum + " a\n");
                } else {
                    tokens.add(new Token("&&", "AND"));
                    i++;
                }
            } else if (stream.charAt(i) == '|') {
                i++;
                if (i == stream.length() || stream.charAt(i) != '|') {
                    printError(lineNum + " a\n");
                } else {
                    tokens.add(new Token("||", "OR"));
                    i++;
                }
            } else if (stream.charAt(i) == '/') {
                i++;
                if (i == stream.length()) {
                    tokens.add(new Token("/", "DIV"));
                } else if (stream.charAt(i) == '/') {
                    while(stream.charAt(i)!='\n'){
                        i++;
                    }
                } else if (stream.charAt(i) == '*') {
                    i++;
                    while(!(stream.charAt(i)=='*'&&stream.charAt(i+1)=='/')){
                        i++;
                        if (stream.charAt(i) == '\n') {
                            lineNum++;
                            //System.out.println("line:" + lineNum);
                        }
                    }
                    i+=2;
                } else {
                    tokens.add(new Token("/", "DIV"));
                }
            } else if (stream.charAt(i) == '+') {
                i++;
                tokens.add(new Token("+", "PLUS"));
            } else if (stream.charAt(i) == '-') {
                i++;
                tokens.add(new Token("-", "MINU"));
            } else if (stream.charAt(i) == '*') {
                i++;
                tokens.add(new Token("*", "MULT"));
            } else if (stream.charAt(i) == '%') {
                i++;
                tokens.add(new Token("%", "MOD"));
            } else if (stream.charAt(i) == ';') {
                i++;
                tokens.add(new Token(";", "SEMICN"));
            } else if (stream.charAt(i) == ',') {
                i++;
                tokens.add(new Token(",", "COMMA"));
            } else if (stream.charAt(i) == '(') {
                i++;
                tokens.add(new Token("(", "LPARENT"));
            } else if (stream.charAt(i) == ')') {
                i++;
                tokens.add(new Token(")", "RPARENT"));
            } else if (stream.charAt(i) == '[') {
                i++;
                tokens.add(new Token("[", "LBRACK"));
            } else if (stream.charAt(i) == ']') {
                i++;
                tokens.add(new Token("]", "RBRACK"));
            } else if (stream.charAt(i) == '{') {
                i++;
                tokens.add(new Token("{", "LBRACE"));
            } else if (stream.charAt(i) == '}') {
                i++;
                tokens.add(new Token("}", "RBRACE"));
            }
        }
    }

    public void printError(String str) {
        String outputFilePath = "error.txt";
        try (FileWriter fw = new FileWriter(outputFilePath, true)) { // true表示追加
            fw.write(str);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
