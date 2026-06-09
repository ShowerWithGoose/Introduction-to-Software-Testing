import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Compiler{
    public static void main(String[] args) {
        //ArrayList <ArrayList<Character>> charList = new ArrayList<>();\
        ArrayList<Character> charList = new ArrayList<>();
        ArrayList<Token> tokens = new ArrayList<>();
        //ArrayList<ERROR> errors = new ArrayList<>();
        Token token;
        int lineNum = 1;
        try (Scanner sc = new Scanner(new FileReader("testfile.txt"))) {
            while (sc.hasNextLine()) { //按行读取字符串
                String line = sc.nextLine();
                //ArrayList lineList = new ArrayList<Character>();
                for (char c : line.toCharArray()) {
                    charList.add(c);
                }
                charList.add('\n');
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        for(int i = 0; i < charList.size(); i++) {
            switch(charList.get(i)) {
                case ' ':
                    break;
                case '\n':
                    lineNum++;
                    break;
                case '/':
                    if (charList.get(i + 1) == '/') {
                        i = i + 2;// 从//之后开始读入，到第一个换行，停在\n
                        while (charList.get(i) != '\n') {
                            i++;
                        } i--;
                    } else if (charList.get(i + 1) == '*') {
                        i = i + 2;// 从/*之后第一个开始读入，停在\n
                        while (!(charList.get(i) == '*' && charList.get(i + 1) == '/')) {
                            if (charList.get(i) == '\n') {
                                lineNum++;
                            }
                            i++;
                        }
                        i++;//停在/
                    } else {
                        token = new Token("/", Cate.DIV,lineNum);
                        tokens.add(token);
                    }
                    break;
                case '!':
                    if (charList.get(i + 1) == '=') {
                        i++;
                        token = new Token("!=", Cate.NEQ,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token("!", Cate.NOT,lineNum);
                        tokens.add(token);
                    }
                    break;
                case '<':
                    if (charList.get(i + 1) == '=') {
                        i++;
                        token = new Token("<=", Cate.LEQ,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token("<", Cate.LSS,lineNum);
                        tokens.add(token);
                    }
                    break;
                case '>':
                    if (charList.get(i + 1) == '=') {
                        i++;
                        token = new Token(">=", Cate.GEQ,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token(">", Cate.GRE,lineNum);
                        tokens.add(token);
                    }
                    break;
                case '=':
                    if (charList.get(i + 1) == '=') {
                        i++;
                        token = new Token("==", Cate.EQL,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token("=", Cate.ASSIGN,lineNum);
                        tokens.add(token);
                    }
                    break;
                case '|':
                    if (charList.get(i + 1) == '|') {
                        i++;
                        token = new Token("||", Cate.OR,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token("|", Cate.OR,lineNum);
                        tokens.add(token);
                        ERROR error1 = new ERROR(lineNum, 'a');
                        //errors.add(error1);
                        ERRORS.addError(error1);
                    }
                    break;
                case '&':
                    if (charList.get(i + 1) == '&') {
                        i++;
                        token = new Token("&&", Cate.AND,lineNum);
                        tokens.add(token);
                    } else {
                        token = new Token("&", Cate.AND,lineNum);
                        tokens.add(token);
                        ERROR error2 = new ERROR(lineNum, 'a');
                        //errors.add(error2);
                        ERRORS.addError(error2);
                    }
                    break;
                case '+':
                    token = new Token("+", Cate.PLUS,lineNum);
                    tokens.add(token);
                    break;
                case '-':
                    token = new Token("-", Cate.MINU,lineNum);
                    tokens.add(token);
                    break;
                case '*':
                    token = new Token("*", Cate.MULT,lineNum);
                    tokens.add(token);
                    break;
                case '%':
                    token = new Token("%", Cate.MOD,lineNum);
                    tokens.add(token);
                    break;
                case ';':
                    token = new Token(";", Cate.SEMICN,lineNum);
                    tokens.add(token);
                    break;
                case ',':
                    token = new Token(",", Cate.COMMA,lineNum);
                    tokens.add(token);
                    break;
                case '(':
                    token = new Token("(", Cate.LPARENT,lineNum);
                    tokens.add(token);
                    break;
                case ')':
                    token = new Token(")", Cate.RPARENT,lineNum);
                    tokens.add(token);
                    break;
                case '[':
                    token = new Token("[", Cate.LBRACK,lineNum);
                    tokens.add(token);
                    break;
                case ']':
                    token = new Token("]", Cate.RBRACK,lineNum);
                    tokens.add(token);
                    break;
                case '{':
                    token = new Token("{", Cate.LBRACE,lineNum);
                    tokens.add(token);
                    break;
                case '}':
                    token = new Token("}", Cate.RBRACE,lineNum);
                    tokens.add(token);
                    break;
                case '\'':
                    StringBuilder string1 = new StringBuilder();
                    string1.append('\'');
                    i++;
                    while (charList.get(i) != '\'') {
                        string1.append(charList.get(i));
                        i++;
                        if (charList.get(i-1) == '\\') {
                            string1.append(charList.get(i));
                            i++;
                        }
                    }
                    string1.append('\'');
                    token = new Token(string1.toString(), Cate.CHRCON,lineNum);
                    tokens.add(token);
                    break;
                case '"':
                    StringBuilder string2 = new StringBuilder();
                    string2.append('"');
                    i++;
                    while (charList.get(i) != '"') {
                        string2.append(charList.get(i));
                        i++;
                    }
                    string2.append('"');
                    token = new Token(string2.toString(), Cate.STRCON,lineNum);
                    tokens.add(token);
                    break;
                default:
                    if (charList.get(i) == '_') {
                        StringBuilder string3 = new StringBuilder();
                        string3.append('_');
                        while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                || Character.isDigit(charList.get(i + 1))) {
                            string3.append(charList.get(i + 1));
                            i++;
                        }
                        token = new Token(string3.toString(), Cate.IDENFR,lineNum);
                        tokens.add(token);
                    } else if (Character.isDigit(charList.get(i))) {
                        boolean isD = true;
                        StringBuilder string4 = new StringBuilder();
                        string4.append(charList.get(i));
                        while (Character.isDigit(charList.get(i + 1))) {
                            string4.append(charList.get(i + 1));
                            i++;
                        }
                        while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                || Character.isDigit(charList.get(i + 1))) {
                            isD = false;
                            string4.append(charList.get(i + 1));
                            i++;
                        }
                        if (isD) {
                            token = new Token(string4.toString(), Cate.INTCON,lineNum);
                        } else {
                            token = new Token(string4.toString(), Cate.IDENFR,lineNum);
                        }
                        tokens.add(token);
                    } else if (Character.isLetter(charList.get(i))) {
                        boolean isTK;
                        StringBuilder string5 = new StringBuilder();
                        //main
                        if (charList.get(i) == 'm' && charList.size() - i >= 4) {
                            if (charList.get(i + 1) == 'a' && charList.get(i + 2) == 'i'
                                    && charList.get(i + 3) == 'n') {
                                for (int j = 0; j < 4; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 3;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.MAINTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                /*string5.add(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.add(charList.get(i + 1));
                                    i++;
                                } token = new Token(string5.toString(),Cate.IDENFR,lineNum);*/
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }
                        else if (charList.get(i) == 'c') {
                            //const
                            if (charList.size() - i >= 5 && charList.get(i + 1) == 'o' && charList.get(i + 2) == 'n'
                                    && charList.get(i + 3) == 's' && charList.get(i + 4) == 't') {
                                for (int j = 0; j < 5; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 4;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.CONSTTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            }//char
                            else if (charList.size() - i >= 4 && charList.get(i + 1) == 'h' && charList.get(i + 2) == 'a'
                                    && charList.get(i + 3) == 'r') {
                                for (int j = 0; j < 4; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 3;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.CHARTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else if (charList.size() - i >= 8 && charList.get(i + 1) == 'o' && charList.get(i + 2) == 'n'
                                    && charList.get(i + 3) == 't' && charList.get(i + 4) == 'i'
                                    && charList.get(i + 5) == 'n' && charList.get(i + 6) == 'u'
                                    && charList.get(i + 7) == 'e') {
                                for (int j = 0; j < 8; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 7;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.CONTINUETK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            }
                            else {
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//int
                        else if (charList.get(i) == 'i') {
                            if (charList.size() - i >= 3 && charList.get(i + 1) == 'n' && charList.get(i + 2) == 't') {
                                for (int j = 0; j < 3; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 2;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.INTTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else if (charList.size() - i >= 2 && charList.get(i + 1) == 'f') {//if
                                for (int j = 0; j < 2; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 1;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.IFTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//break
                        else if (charList.get(i) == 'b' && charList.size() - i >= 5) {
                            if (charList.get(i + 1) == 'r' && charList.get(i + 2) == 'e'
                                    && charList.get(i + 3) == 'a' && charList.get(i + 4) == 'k') {
                                for (int j = 0; j < 5; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 4;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.BREAKTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//else
                        else if (charList.get(i) == 'e' && charList.size() - i >= 4) {
                            if (charList.get(i + 1) == 'l' && charList.get(i + 2) == 's'
                                    && charList.get(i + 3) == 'e') {
                                for (int j = 0; j < 4; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 3;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.ELSETK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//for
                        else if (charList.get(i) == 'f' && charList.size() - i >= 3) {
                            if (charList.get(i + 1) == 'o' && charList.get(i + 2) == 'r') {
                                for (int j = 0; j < 3; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 2;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.FORTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//getint
                        else if (charList.get(i) == 'g') {
                            if (charList.size() - i >= 6 && charList.get(i + 1) == 'e' && charList.get(i + 2) == 't'
                                    && charList.get(i + 3) == 'i' && charList.get(i + 4) == 'n'
                                    && charList.get(i + 5) == 't') {
                                for (int j = 0; j < 6; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 5;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.GETINTTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else if (charList.size() - i >= 7 && charList.get(i + 1) == 'e' && charList.get(i + 2) == 't'
                                    && charList.get(i + 3) == 'c' && charList.get(i + 4) == 'h'
                                    && charList.get(i + 5) == 'a' && charList.get(i + 6) == 'r') {
                                for (int j = 0; j < 7; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 6;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.GETCHARTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            }
                            else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//printf
                        else if (charList.get(i) == 'p' && charList.size() - i >= 6) {
                            if (charList.get(i + 1) == 'r' && charList.get(i + 2) == 'i'
                                    && charList.get(i + 3) == 'n' && charList.get(i + 4) == 't'
                                    && charList.get(i + 5) == 'f') {
                                for (int j = 0; j < 6; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 5;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                token = new Token(string5.toString(), Cate.PRINTFTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//return
                        else if (charList.get(i) == 'r' && charList.size() - i >= 6) {
                            if (charList.get(i + 1) == 'e' && charList.get(i + 2) == 't'
                                    && charList.get(i + 3) == 'u' && charList.get(i + 4) == 'r'
                                    && charList.get(i + 5) == 'n') {
                                for (int j = 0; j < 6; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 5;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.RETURNTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        }//void
                        else if (charList.get(i) == 'v' && charList.size() - i >= 4) {
                            if (charList.get(i + 1) == 'o' && charList.get(i + 2) == 'i'
                                    && charList.get(i + 3) == 'd') {
                                for (int j = 0; j < 4; j++) {
                                    string5.append(charList.get(i + j));
                                }
                                isTK = true;
                                i = i + 3;
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    isTK = false;
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                if (isTK) {
                                    token = new Token(string5.toString(), Cate.VOIDTK,lineNum);
                                } else {
                                    token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                                }
                            } else {
                                
                                string5.append(charList.get(i));
                                while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                        || Character.isDigit(charList.get(i + 1))) {
                                    string5.append(charList.get(i + 1));
                                    i++;
                                }
                                token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                            }
                        } else {
                            string5.append(charList.get(i));
                            while (charList.get(i + 1) == '_' || Character.isLetter(charList.get(i + 1))
                                    || Character.isDigit(charList.get(i + 1))) {
                                string5.append(charList.get(i + 1));
                                i++;
                            }
                            token = new Token(string5.toString(), Cate.IDENFR,lineNum);
                        }
                        tokens.add(token);
                    }
                    break;
            }
        }
        //词法分析的输出
        /*if (errors.isEmpty()) {
            for (Token t : tokens) {
                try {
                    t.Print();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } else {
            for (int k = 0; k < errors.size(); k++) {
                errors.get(k).print();
            }
        }*/
        parser(tokens);
    }

    private static void parser(ArrayList<Token> tokens) {
        CompUnit compUnit = new CompUnit(tokens);
        compUnit.parser();
        try {
            compUnit.Print();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}