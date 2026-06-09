package frontend;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Lexer {
    private ArrayList<String> text;
    public Lexer(ArrayList<String> text) {
        this.text = text;
    }
    public ArrayList<Word> analyze() throws IOException {
        ArrayList<Word> words = new ArrayList<>();
        int lineNum = 0,flag = 0; //flag表示注释
        for(int i=0;i< text.size();i++) {
            lineNum = i + 1;
            String line = text.get(i);
            int idx = 0;
            while(idx < line.length()) {
                char c = line.charAt(idx++);
                if (flag == 1) {
                    if(c == '*' && idx <line.length()) {
                        c = line.charAt(idx++);
                        if(c == '/') {
                            flag = 0;
                        }
                    }
                    continue;
                }
                if (c == '!') {
                    if (line.charAt(idx) == '=') {
                        idx++;
                        words.add(new Word(WordType.NEQ,"!=",lineNum));
                    } else {
                        words.add(new Word(WordType.NOT,"!",lineNum));
                    }

                } else if (c == '+') {
                    words.add(new Word(WordType.PLUS,"+",lineNum));
                } else if (c == '-') {
                    words.add(new Word(WordType.MINU,"-",lineNum));
                } else if (c == '*') {
                    words.add(new Word(WordType.MULT,"*",lineNum));
                } else if (c == '/') {
                    c = line.charAt(idx++);
                    if (c == '/') {
                        idx = line.length();
                    } else if(c == '*') {
                        flag = 1;
                    } else {
                        idx--;
                        words.add(new Word(WordType.DIV,"/",lineNum));
                    }

                } else if (c == '%') {
                    words.add(new Word(WordType.MOD,"%",lineNum));
                } else if (c == '<') {
                    if (line.charAt(idx) == '=') {
                        idx++;
                        words.add(new Word(WordType.LEQ,"<=",lineNum));
                    } else {
                        words.add(new Word(WordType.LSS,"<",lineNum));
                    }

                } else if (c == '>') {
                    if (line.charAt(idx) == '=') {
                        idx++;
                        words.add(new Word(WordType.GEQ, ">=", lineNum));
                    } else {
                        words.add(new Word(WordType.GRE, ">", lineNum));
                    }
                } else if (c == '=') {
                     if (line.charAt(idx) == '=') {
                         idx++;
                         words.add(new Word(WordType.EQL,"==",lineNum));
                     } else {
                         words.add(new Word(WordType.ASSIGN, "=", lineNum));
                     }
                } else if (c == ';') {
                    words.add(new Word(WordType.SEMICN,";",lineNum));
                } else if (c == ',') {
                    words.add(new Word(WordType.COMMA,",",lineNum));
                } else if (c == '(') {
                    words.add(new Word(WordType.LPARENT,"(",lineNum));
                } else if (c == ')') {
                    words.add(new Word(WordType.RPARENT,")",lineNum));
                } else if (c == '[') {
                    words.add(new Word(WordType.LBRACK,"[",lineNum));
                } else if (c == ']') {
                    words.add(new Word(WordType.RBRACK,"]",lineNum));
                } else if (c == '{') {
                    words.add(new Word(WordType.LBRACE,"{",lineNum));
                } else if (c == '}') {
                    words.add(new Word(WordType.RBRACE,"}",lineNum));
                } else if (isIdentifierNonDigit(c)) {
                    StringBuilder stringBuilder = new StringBuilder();
                    stringBuilder.append(c);
                    while(idx < line.length()) {
                        c = line.charAt(idx++);
                        if (isIdentifierOrDigit(c)) {
                            stringBuilder.append(c);
                        } else{
                            idx--;
                            break;
                        }
                    }
                    String s = stringBuilder.toString();
                    if (s.equals("main")) {
                        words.add(new Word(WordType.MAINTK, s, lineNum));
                    } else if (s.equals("const")) {
                        words.add(new Word(WordType.CONSTTK, s, lineNum));
                    } else if (s.equals("int")) {
                        words.add(new Word(WordType.INTTK, s, lineNum));
                    } else if (s.equals("char")) {
                        words.add(new Word(WordType.CHARTK, s, lineNum));
                    } else if (s.equals("break")) {
                        words.add(new Word(WordType.BREAKTK, s, lineNum));
                    } else if (s.equals("continue")) {
                        words.add(new Word(WordType.CONTINUETK, s, lineNum));
                    } else if (s.equals("if")) {
                        words.add(new Word(WordType.IFTK, s, lineNum));
                    } else if (s.equals("else")) {
                        words.add(new Word(WordType.ELSETK, s, lineNum));
                    } else if (s.equals("for")) {
                        words.add(new Word(WordType.FORTK, s, lineNum));
                    } else if (s.equals("getint")) {
                        words.add(new Word(WordType.GETINTTK, s, lineNum));
                    } else if (s.equals("getchar")) {
                        words.add(new Word(WordType.GETCHARTK, s, lineNum));
                    } else if (s.equals("printf")) {
                        words.add(new Word(WordType.PRINTFTK, s, lineNum));
                    } else if (s.equals("return")) {
                        words.add(new Word(WordType.RETURNTK, s, lineNum));
                    } else if (s.equals("void")) {
                        words.add(new Word(WordType.VOIDTK, s, lineNum));
                    } else {
                        words.add(new Word(WordType.IDENFR, s, lineNum));
                    }
                } else if (c == '"') {
                    StringBuilder stringBuilder = new StringBuilder();
                    stringBuilder.append('"');
                    while((c = line.charAt(idx++)) != '"') {
                        if (c =='\\') {
                            c = line.charAt(idx++);
                            if(c == 'n') {
                                stringBuilder.append("\\n");
                            }
                        }else {
                            stringBuilder.append(c);
                        }

                    }
                    stringBuilder.append('"');
                    words.add(new Word(WordType.STRCON,stringBuilder.toString(),lineNum));
                } else if(c == '\''){
                    StringBuilder stringBuilder = new StringBuilder();
                    stringBuilder.append("'");
                    while ((c = line.charAt(idx++)) != '\'') {
                        if(c != '\\') {
                            stringBuilder.append(c);
                        } else {
                            c = line.charAt(idx++);
                            char ch = '\0';
                            if (c == 'a') {
                                ch = 7;
//                                stringBuilder.append(ch);
                            } else if(c == 'b') {
                                ch = 8;
//                                stringBuilder.append("\\b");
                            } else if(c == 't') {
                                ch = 9;
//                                stringBuilder.append("\\t");
                            } else if(c == 'n') {
                                ch = 10;
//                                stringBuilder.append("\\n");
                            } else if(c == 'v') {
                                ch = 11;
//                                stringBuilder.append("\\v");
                            } else if(c == 'f') {
                                ch = 12;
//                                stringBuilder.append("\\f");
                            } else if(c == '"') {
                                ch = 34;
//                                stringBuilder.append("\\\"");
                            } else if(c == '\'') {
                                ch = 39;
//                                stringBuilder.append("\\'");
                            } else if(c == '\\') {
                                ch = 92;
//                                stringBuilder.append("\\\\");
                            } else if(c == '0') {
                                ch = 0;
 //                               stringBuilder.append("\0");
                            }
                            stringBuilder.append(ch);
                        }
                    }
                    stringBuilder.append("'");
                    words.add(new Word(WordType.CHRCON,stringBuilder.toString(),lineNum));
                } else if(isdigit(c)) {
                    StringBuilder stringBuilder = new StringBuilder();
                    stringBuilder.append(c);
                    while(isdigit(c = line.charAt(idx++))) {
                        stringBuilder.append(c);
                    }
                    idx--;
                    words.add(new Word(WordType.INTCON,stringBuilder.toString(),lineNum));
                } else if(c == '&') {
                    if((c = line.charAt(idx++)) == '&') {
                        words.add(new Word(WordType.AND,"&&",lineNum));
                    } else {
                        words.clear();
                        File file = new File("error.txt");
                        file.createNewFile();
                        FileWriter fw = new FileWriter("error.txt");
                        PrintWriter pw = new PrintWriter(fw);
                        pw.println(lineNum+" a");
                        pw.flush();
                        return words;
                    }
                } else if(c == '|') {
                    if((c = line.charAt(idx++)) == '|') {
                        words.add(new Word(WordType.OR,"||",lineNum));
                    } else {
                        words.clear();
                        File file = new File("error.txt");
                        file.createNewFile();
                        FileWriter fw = new FileWriter("error.txt");
                        PrintWriter pw = new PrintWriter(fw);
                        pw.println(lineNum+" a");
                        pw.flush();
                        return words;
                    }
                }
            }
        }
        File file = new File("lexer.txt");
        file.createNewFile();
        FileWriter fw = new FileWriter("lexer.txt");
        PrintWriter pw = new PrintWriter(fw);
        for(int i=0;i< words.size();i++) {
            Word word = words.get(i);
            pw.println(word.getType()+" "+word.getName());
            pw.flush();
        }
        return words;
    }
    public boolean isdigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    public boolean isAlpha(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
    public boolean isIdentifierNonDigit(char ch) {
        return (isAlpha(ch) || ch == '_');
    }
    public boolean isIdentifierOrDigit(char ch) {
        return isdigit(ch) || isIdentifierNonDigit(ch);
    }
}
