import node.Token;
import node.TokenList;
import node.TokenType;
import node.tokenError;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

public class Lexer {
    private TokenList tokens;
    private ArrayList<tokenError> tokenErrors;
    private int index;
    private int numLine;

    public Lexer() {
        this.tokens = new TokenList();
        this.tokenErrors = new ArrayList<>();
        this.index = 0;
        this.numLine = 0;
    }

    public void tokenize(String content) {
        numLine = 1;
        while (index < content.length()) {
            while (index < content.length() && (content.charAt(index) == '\n' || content.charAt(index) == ' ' )) {
                if (content.charAt(index) == '\n') {
                    numLine++;
                }
                index++;
            }
            if (index >= content.length()) {
                break;
            }
            //System.out.println("this time" + content.charAt(index));
            if (classifier(content.charAt(index))) {
                notSymbol(content);
            } else {
                Symbol(content);
            }
        }

    }

    public TokenList getTokens() {
        return tokens;
    }

    public ArrayList<tokenError> getTokenErrors() {
        return tokenErrors;
    }

    public void printAns() {
        if (tokenErrors.isEmpty()) {
            try {
                FileOutputStream fos = new FileOutputStream("lexer.txt");
                PrintStream ps = new PrintStream(fos);
                System.setOut(ps);
                //FileWriter writer = new FileWriter("lexer.txt");
                tokens.print();
                //System.out.println("Data written to file successfully.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        } else {
            try {
                FileWriter writer = new FileWriter("error.txt");
                for (tokenError e : tokenErrors) {
                    writer.write(e.toString() + '\n');
                }
                writer.close();
                //System.out.println("Data written to file successfully.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }

        }
    }

    public boolean classifier(char s) {
        return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9') || (s == '_');
    }

    public void notSymbol(String content) {
        while (content.charAt(index) == '\n' || content.charAt(index) == ' ') {
            if (content.charAt(index) == '\n') {
                numLine++;
            }
            index++;
        }

        if (content.charAt(index) >= '0' && content.charAt(index) <= '9') {
            catchIntConst(content);
        } else if (content.charAt(index) == '_' || (content.charAt(index) >= 'A' && content.charAt(index) <= 'Z')) {
            catchIdent(content);
        } else {
            switch (content.charAt(index)) {
                case 'm':
                    if (index + 3 < content.length() && content.substring(index,index + 4).equals("main")
                        && (index + 4 >= content.length() || !classifier(content.charAt(index + 4)))) {
                        tokens.add(new Token("main", TokenType.MAINTK,numLine));
                        index = index + 4;
                    }
                    else {
                        catchIdent(content);
                    }
                    break;
                case 'c':
                    if (index + 3 < content.length() && content.substring(index,index + 4).equals("char")
                            && (index + 4 >= content.length() || !classifier(content.charAt(index + 4)))) {
                        tokens.add(new Token("char",TokenType.CHARTK,numLine));
                        index = index + 4;
                    } else if (index + 4 < content.length() && content.substring(index,index + 5).equals("const")
                            && (index + 5 >= content.length() || !classifier(content.charAt(index + 5)))) {
                        tokens.add(new Token("const",TokenType.CONSTTK,numLine));
                        index = index + 5;
                    } else if (index + 7 < content.length() && content.substring(index,index + 8).equals("continue")
                            && (index + 8 >= content.length() || !classifier(content.charAt(index + 8)))) {
                        tokens.add(new Token("continue",TokenType.CONTINUETK,numLine));
                        index = index + 8;
                    }
                    else {
                        catchIdent(content);
                    }
                    break;
                case 'i':
                    if (index + 2 < content.length() && content.substring(index,index + 3).equals("int")
                            && (index + 3 >= content.length() || !classifier(content.charAt(index + 3)))) {
                        tokens.add(new Token("int",TokenType.INTTK,numLine));
                        index = index + 3;
                    } else if (index + 1 < content.length() && content.substring(index,index + 2).equals("if")
                            && (index + 2 >= content.length() || !classifier(content.charAt(index + 2)))) {
                        tokens.add(new Token("if",TokenType.IFTK,numLine));
                        index = index + 2;
                    }
                    else {
                        catchIdent(content);
                    }
                    break;
                case 'b':
                    if (index + 4 < content.length() && content.substring(index,index + 5).equals("break")
                            && (index + 5 >= content.length() || !classifier(content.charAt(index + 5)))) {
                        tokens.add(new Token("break",TokenType.BREAKTK,numLine));
                        index = index + 5;
                    } else {
                        catchIdent(content);
                    }
                    break;
                case 'f':
                    if (index + 2 < content.length() && content.substring(index,index + 3).equals("for")
                            && (index + 3 >= content.length() || !classifier(content.charAt(index + 3)))) {
                        tokens.add(new Token("for",TokenType.FORTK,numLine));
                        index = index + 3;
                    } else {
                        catchIdent(content);
                    }
                    break;
                case 'e':
                    if (index + 3 < content.length() && content.substring(index,index + 4).equals("else")
                            && (index + 4 >= content.length() || !classifier(content.charAt(index + 4)))) {
                        tokens.add(new Token("else",TokenType.ELSETK,numLine));
                        index = index + 4;
                    }
                    else {
                        catchIdent(content);
                    }
                    break;
                case 'g':
                    if (index + 5 < content.length() && content.substring(index,index + 6).equals("getint")
                            && (index + 6 >= content.length() || !classifier(content.charAt(index + 6)))) {
                        tokens.add(new Token("getint",TokenType.GETINTTK,numLine));
                        index = index + 6;
                    } else if (index + 6 < content.length() && content.substring(index,index + 7).equals("getchar")
                            && (index + 7 >= content.length() || !classifier(content.charAt(index + 7)))) {
                        tokens.add(new Token("getchar",TokenType.GETCHARTK,numLine));
                        index = index + 7;
                    }
                    else {
                        catchIdent(content);
                    }
                    break;
                case 'p':
                    if (index + 5 < content.length() && content.substring(index,index + 6).equals("printf")
                            && (index + 6 >= content.length() || !classifier(content.charAt(index + 6)))) {
                        tokens.add(new Token("printf",TokenType.PRINTFTK,numLine));
                        index = index + 6;
                    } else {
                        catchIdent(content);
                    }
                    break;
                case 'r':
                    if (index + 5 < content.length() && content.substring(index,index + 6).equals("return")
                            && (index + 6 >= content.length() || !classifier(content.charAt(index + 6)))) {
                        tokens.add(new Token("return",TokenType.RETURNTK,numLine));
                        index = index + 6;
                    } else {
                        catchIdent(content);
                    }
                    break;
                case 'v':
                    if (index + 3 < content.length() && content.substring(index,index + 4).equals("void")
                            && (index + 4 >= content.length() || !classifier(content.charAt(index + 4)))) {
                        tokens.add(new Token("void",TokenType.VOIDTK,numLine));
                        index = index + 4;
                    } else {
                        catchIdent(content);
                    }
                    break;
                default:
                    catchIdent(content);
                    break;
            }
        }

    }

    public void catchIntConst(String content) {
        StringBuilder temp = new StringBuilder();
        while (content.charAt(index) >= '0' && content.charAt(index) <= '9') {
            temp.append(content.charAt(index));
            index++;
        }
        //index --;
        tokens.add(new Token(temp.toString(),TokenType.INTCON,numLine));
    }
    public void catchIdent(String content) {
        StringBuilder temp = new StringBuilder();
        temp.append(content.charAt(index));
        index++;
        while (classifier(content.charAt(index))) {
            temp.append(content.charAt(index));
            index++;
        }
        tokens.add(new Token(temp.toString(),TokenType.IDENFR,numLine));
    }

    public void Symbol(String content) {
        while (content.charAt(index) == '\n' || content.charAt(index) == ' ') {
            if (content.charAt(index) == '\n') {
                numLine++;
            }
            index++;
        }
        switch (content.charAt(index)) {
            case ' ':
                index++;
                break;
            case '\n':
                index++;
                numLine++;
                break;
            case '!':
                if (content.charAt(index + 1) != '=') {
                    tokens.add(new Token("!", TokenType.NOT, numLine));
                    index++;
                } else {
                    index++;
                    index++;
                    tokens.add(new Token("!=",TokenType.NEQ,numLine));
                }
                break;
            case '&':
                if (content.charAt(index + 1) != '&') {
                    tokenError error = new tokenError(numLine,"a");
                    tokenErrors.add(error);
                    index ++;
                    tokens.add(new Token("&&",TokenType.AND,numLine));
                } else {
                    index++;
                    index++;
                    tokens.add(new Token("&&",TokenType.AND,numLine));
                }
                break;
            case '|':
                if (content.charAt(index + 1) != '|') {
                    tokenError error = new tokenError(numLine,"a");
                    tokenErrors.add(error);
                    index ++;
                    tokens.add(new Token("||",TokenType.OR,numLine));
                } else {
                    index++;
                    index++;
                    tokens.add(new Token("||",TokenType.OR,numLine));
                }
                break;
            case '+':
                index++;
                tokens.add(new Token("+",TokenType.PLUS,numLine));
                break;
            case '-':
                index++;
                tokens.add(new Token("-",TokenType.MINU,numLine));
                break;
            case '*':
                index++;
                tokens.add(new Token("*",TokenType.MULT,numLine));
                break;
            case '/':
                if (content.charAt(index + 1) == '/') {
                    index++;
                    index++;
                    while (index < content.length() && content.charAt(index) != '\n') {
                        index++;
                    }
                    numLine++;
                    index++;
                } else if (content.charAt(index + 1) == '*'){
                    index++;
                    index++;
                    int pre_index3 = index;
                    index++;
                    while (content.charAt(index) != '/'  || content.charAt(pre_index3) != '*') {
                        if (content.charAt(pre_index3) == '\n') {
                            numLine++;
                        }
                        pre_index3 = index;
                        index++;
                    }
                    index++;
                }
                else {
                    index++;
                    tokens.add(new Token("/",TokenType.DIV,numLine));

                }
                break;

            case '%':
                index++;
                tokens.add(new Token("%",TokenType.MOD,numLine));
                break;
            case '<':
                if (content.charAt(index + 1) != '=') {
                    index++;
                    tokens.add(new Token("<", TokenType.LSS, numLine));
                } else {
                    index++;
                    index++;
                    tokens.add(new Token("<=",TokenType.LEQ,numLine));
                }
                break;
            case '>':
                if (content.charAt(index + 1) != '=') {
                    index++;
                    tokens.add(new Token(">",TokenType.GRE,numLine));
                } else {
                    index++;
                    index++;
                    tokens.add(new Token(">=",TokenType.GEQ,numLine));
                }
                break;
            case '=':
                if (content.charAt(index + 1) != '=') {
                    index++;
                    tokens.add(new Token("=",TokenType.ASSIGN,numLine));
                } else {
                    index++;
                    index++;
                    tokens.add(new Token("==",TokenType.EQL,numLine));
                }
                break;
            case ';':
                index++;
                tokens.add(new Token(";",TokenType.SEMICN,numLine));
                break;
            case ',':
                index++;
                tokens.add(new Token(",",TokenType.COMMA,numLine));
                break;
            case '(':
                index++;
                tokens.add(new Token("(",TokenType.LPARENT,numLine));
                break;
            case ')':
                index++;
                tokens.add(new Token(")",TokenType.RPARENT,numLine));
                break;
            case '[':
                index++;
                tokens.add(new Token("[",TokenType.LBRACK,numLine));
                break;
            case ']':
                index++;
                tokens.add(new Token("]",TokenType.RBRACK,numLine));
                break;
            case '{':
                index++;
                tokens.add(new Token("{",TokenType.LBRACE,numLine));
                break;
            case '}':
                index++;
                tokens.add(new Token("}",TokenType.RBRACE,numLine));
                break;
            case '\'':
                StringBuilder temp = new StringBuilder();
                int pre_index = index;
                temp.append(content.charAt(index));
                index++;
                int check = 0;
                while (content.charAt(index) != '\'' || (content.charAt(pre_index) == '\\' && check == 0)) {
                    temp.append(content.charAt(index));
                    if ((content.charAt(pre_index) == '\\' && content.charAt(index) == '\\')) {
                        check = 1;
                    }
                    pre_index = index;
                    index++;
                }
                temp.append(content.charAt(index));
                index++;
                tokens.add(new Token(temp.toString(),TokenType.CHRCON,numLine));
                break;

            case '\"':
                StringBuilder temp2 = new StringBuilder();
                int pre_index2 = index;
                temp2.append(content.charAt(index));
                index++;
                int check1 = 0;
                while (content.charAt(index) != '\"' || content.charAt(pre_index2) == '\\' && check1 == 0) {
                    temp2.append(content.charAt(index));
                    if ((content.charAt(pre_index2) == '\\' && content.charAt(index) == '\\')) {
                        check1 = 1;
                    }
                    pre_index2 = index;
                    index++;
                }
                temp2.append(content.charAt(index));
                index++;
                tokens.add(new Token(temp2.toString(),TokenType.STRCON,numLine));
                break;
            default:
                //System.out.println("未知符号" + (int)content.charAt(index));
                index++;
                break;
        }
    }
}
