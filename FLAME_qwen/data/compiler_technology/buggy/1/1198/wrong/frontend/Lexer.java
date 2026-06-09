package frontend;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private static final HashMap<String, Single> singles = new HashMap<>();
    public static final ArrayList<Lexer_out> outs = new ArrayList<>();
    public static final ArrayList<WrongExample> ws = new ArrayList<>();
    public static void run() {
        singles.put("main", new Single("main", "MAINTK"));
        singles.put("const", new Single("const", "CONSTTK"));
        singles.put("int", new Single("int", "INTTK"));
        singles.put("char", new Single("char", "CHARTK"));
        singles.put("break", new Single("break", "BREAKTK"));
        singles.put("continue", new Single("continue", "CONTINUETK"));
        singles.put("if", new Single("if", "IFTK"));
        singles.put("else", new Single("else", "ELSETK"));
        singles.put("&&", new Single("&&", "AND"));
        singles.put("||", new Single("||", "OR"));
        singles.put("for", new Single("for", "FORTK"));
        singles.put("getint", new Single("getint", "GETINTTK"));
        singles.put("getchar", new Single("getchar", "GETCHARTK"));
        singles.put("printf", new Single("printf", "PRINTFTK"));
        singles.put("return", new Single("return", "RETURNTK"));
        singles.put("void", new Single("void", "VOIDTK"));
        singles.put("<=", new Single("<=", "LEQ"));
        singles.put(">=", new Single("==", "EQL"));
        singles.put("!=", new Single("!=", "NEQ"));
        FileReader f = null;
        int num = 0;
        int line_num = 1;
        int cnt = 0;
        try {
            f = new FileReader("testfile.txt");
            FileWriter x = new FileWriter("lexer.txt");
            FileWriter w = new FileWriter("error.txt");
            int ch = f.read();
            while (ch != -1) {
                if ((char) ch == '/') {
                    ch = f.read();
                    if ((char) ch == '/') { //单行注释
                        while ((char) ch != '\n') {
                            ch = f.read();
                            if(ch == -1) {
                                return;
                            }
                            //System.out.println((char) ch + "!!");
                        }
                        line_num = line_num + 1;
                    } else if ((char) ch == '*') { //多行注释
                        ch = f.read();
                        while (true) {
                            if ((char) ch == '*') {
                                ch = f.read();
                                if((char) ch == '/') {
                                    ch = f.read();
                                    break;
                                } else if (ch == '\n'){
                                    line_num = line_num + 1;
                                } else {
                                    continue;
                                }
                            } else if (ch == '\n') {
                                line_num = line_num + 1;
                            }
                            ch = f.read();
                        }
                        //System.out.println("finish");
                    } else { //输出除号
                        //System.out.println("DIV /");
                        x.write("DIV /\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("DIV","/", line_num));
                        cnt++;
                        continue;
                    }
                }
                if ((char)ch == '"') { //双引号（字符串）
                    //System.out.print("STRCON \"");
                    x.write("STRCON \"");
                    x.flush();
                    ch = f.read();
                    StringBuilder tmp = new StringBuilder("\"");
                    while ((char)ch != '"') {
                        //System.out.print((char) ch);
                        x.write((char) ch);
                        x.flush();
                        tmp.append((char) ch);
                        ch = f.read();
                    }
                    tmp.append('\"');
                    outs.add(cnt,new Lexer_out("STRCON", tmp.toString(), line_num));
                    cnt++;
                    //System.out.println('"');
                    x.write("\"\n");
                    x.flush();
                }
                if ((char)ch == '\'') { //单引号（字符）
                    //System.out.print("CHRCON '");
                    x.write("CHRCON '");
                    x.flush();
                    ch = f.read();
                    StringBuilder tmp = new StringBuilder("'");
                    while ((char)ch != '\'') {
                        //System.out.print((char) ch);
                        x.write((char) ch);
                        x.flush();
                        tmp.append((char) ch);
                        ch = f.read();
                    }
                    //System.out.println('\'');
                    ch = f.read();
                    if((char)ch == '\'') {
                        x.write(String.valueOf("''\n"));
                        x.flush();
                        tmp.append("''");
                        outs.add(cnt, new Lexer_out("CHRCON", tmp.toString(), line_num));
                        cnt++;
                    } else {
                        x.write( "'\n");
                        x.flush();
                        tmp.append("'");
                        outs.add(cnt, new Lexer_out("CHRCON", tmp.toString(), line_num));
                        cnt++;
                        if((char) ch == '\n') {
                            line_num++;
                        }
                        continue;
                    }

                    x.flush();
                }
                if (/*(char) ch == '\n' || (char) ch == '\t' || (char) ch == ' '*/Character.isWhitespace((char) ch)) {
                    ch = f.read();
                    if ((char) ch == '\n') {
                        line_num++;
                    }
                    continue;
                }
                if ((char) ch == '|') {
                    ch = f.read();
                    if ((char) ch == '|') {
                        //System.out.println("OR ||");
                        x.write("OR ||\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("OR","||", line_num));
                        cnt++;
                    } else {
                        w.write(Integer.toString(line_num));
                        w.write(" a\n");
                        w.flush();
                        outs.add(cnt,new Lexer_out("OR","|", line_num));
                        cnt++;
                        ws.add(num, new WrongExample(line_num, "a"));
                        num++;
                        //System.out.println(line_num + " a");
                    }
                }
                if ((char) ch == '&') {
                    ch = f.read();
                    if ((char) ch == '&') {
                        //System.out.println("AND &&");
                        x.write("AND &&\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("AND","&&", line_num));
                        cnt++;
                    } else {
                        outs.add(cnt,new Lexer_out("AND","&", line_num));
                        cnt++;
                        w.write(Integer.toString(line_num));
                        w.write(" a\n");
                        w.flush();
                        ws.add(num, new WrongExample(line_num, "a"));
                        num++;
                        //System.out.println(line_num + " a");
                    }
                }
                if((char) ch == '=') {
                    ch = f.read();
                    if ((char) ch == '=') {
                        x.write("EQL ==\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("EQL","==", line_num));
                        cnt++;
                        //System.out.println("EQL ==");
                    } else {
                        x.write("ASSIGN =\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("ASSIGN","=", line_num));
                        cnt++;
                        //System.out.println("ASSIGN =");
                        if ((char) ch == '\n') {
                            line_num++;
                        }
                        continue;
                    }

                }
                if ((char) ch == '!') {
                    ch = f.read();
                    if((char) ch == '=') {
                        x.write("NEQ !=\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("NEQ","!=", line_num));
                        cnt++;
                        //System.out.println("NEQ !=");
                    } else {
                        x.write("NOT !\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("NOT","!", line_num));
                        cnt++;
                        //System.out.println("NOT !");
                        if ((char) ch == '\n') {
                            line_num++;
                        }
                        continue;
                    }

                }
                if ((char) ch == '>') {
                    ch = f.read();
                    if((char) ch == '=') {
                        x.write("GEQ >=\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("GEQ",">=", line_num));
                        cnt++;
                        //System.out.println("GEQ >=");
                    } else {
                        x.write("GRE >\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("GRE",">", line_num));
                        cnt++;
                        //System.out.println("GRE >");
                        if ((char) ch == '\n') {
                            line_num++;
                        }
                        continue;
                    }

                }
                if ((char) ch == '<') {
                    ch = f.read();
                    if((char) ch == '=') {
                        x.write("LEQ <=\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("LEQ","<=", line_num));
                        cnt++;
                        //System.out.println("LEQ <=");
                    } else {
                        x.write("LSS <\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("LSS","<", line_num));
                        cnt++;
                        //System.out.println("LSS <");
                        if ((char) ch == '\n') {
                            line_num++;
                        }
                        continue;
                    }

                }
                //System.out.print((char) ch);
                //System.out.print("*");
                if ((char) ch == '+') {
                    x.write("PLUS +\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("PLUS","+", line_num));
                    cnt++;
                    //System.out.println("PLUS +");
                }
                if ((char) ch == '-') {
                    x.write("MINU -\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("MINU","-", line_num));
                    cnt++;
                    //System.out.println("MINU -");
                }
                if ((char) ch == '*') {
                    x.write("MULT *\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("MULT","*", line_num));
                    cnt++;
                    //System.out.println("MULT *");
                }
                if ((char) ch == '%') {
                    x.write("MOD %\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("MOD","%", line_num));
                    cnt++;
                    //System.out.println("MOD %");
                }
                if ((char) ch == ';') {
                    x.write("SEMICN ;\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("SEMICN",";", line_num));
                    cnt++;
                    //System.out.println("SEMICN ;");
                }
                if ((char) ch == ',') {
                    x.write("COMMA ,\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("COMMA",",", line_num));
                    cnt++;
                    //System.out.println("COMMA ,");
                }
                if ((char) ch == '(') {
                    x.write("LPARENT (\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("LPARENT","(", line_num));
                    cnt++;
                    //System.out.println("LPARENT (");
                }
                if ((char) ch == ')') {
                    x.write("RPARENT )\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("RPARENT",")", line_num));
                    cnt++;
                    //System.out.println("RPARENT )");
                }
                if ((char) ch == '[') {
                    x.write("LBRACK [\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("LBRACK","[", line_num));
                    cnt++;
                    //System.out.println("LBRACK [");
                }
                if ((char) ch == ']') {
                    x.write("RBRACK ]\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("RBRACK","]", line_num));
                    cnt++;
                    //System.out.println("RBRACK ]");
                }
                if ((char) ch == '{') {
                    x.write("LBRACE {\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("LBRACE","{", line_num));
                    cnt++;
                    //System.out.println("LBRACE {");
                }
                if ((char) ch == '}') {
                    x.write("RBRACE }\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("RBRACE","}", line_num));
                    cnt++;
                    //System.out.println("RBRACE }");
                }
                //单个字符符号

                //两个字符符号
                //数字串/字母串
                if((char) ch <= '9' && (char) ch >= '0') {
                    StringBuilder str = new StringBuilder(String.valueOf((char) ch));
                    ch = f.read();
                    while((char) ch <= '9' && (char) ch >= '0') {
                        str.append((char) ch);
                        ch = f.read();
                    }
                    x.write("INTCON " + str + "\n");
                    x.flush();
                    outs.add(cnt,new Lexer_out("INTCON", str.toString(), line_num));
                    cnt++;
                    //System.out.println("INTCON " + str);
                    if ((char) ch == '\n') {
                        line_num++;
                    }
                    continue;
                } //数字
                if ((char) ch == '_' || ((char) ch <= 'Z' && (char) ch >= 'A') || ((char) ch <= 'z' && (char) ch >= 'a')) {
                    StringBuilder str = new StringBuilder(String.valueOf((char) ch));
                    ch = f.read();
                    while ((char) ch == '_' || ((char) ch <= 'Z' && (char) ch >= 'A') ||
                            ((char) ch <= 'z' && (char) ch >= 'a') || (char) ch <= '9' && (char) ch >= '0'){
                        str.append((char) ch);
                        ch = f.read();
                    }
                    if(singles.containsKey(String.valueOf(str))) {
                        x.write(singles.get(String.valueOf(str)).getType()+ " " +String.valueOf(str) + "\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out(singles.get(String.valueOf(str)).getType(), String.valueOf(str), line_num));
                        cnt++;
                        //System.out.println(singles.get(String.valueOf(str)).getType()+ " " +String.valueOf(str));
                    } else {
                        x.write("IDENFR " + str + "\n");
                        x.flush();
                        outs.add(cnt,new Lexer_out("IDENFR", str.toString(), line_num));
                        cnt++;
                        //System.out.println("IDENFR " + str);
                    }
                    if ((char) ch == '\n') {
                        line_num++;
                    }
                    continue;
                }
                if (ch != -1) {
                    ch = f.read();
                }
                if ((char) ch == '\n') {
                    line_num++;
                }
            }
        } catch (IOException e) {
            //System.out.println("wrong!!!");
            e.printStackTrace();
        }

        /*for(int i = 0; i < outs.size(); i++) {
            System.out.println(outs.get(i).getType() + " " + outs.get(i).getName() + " " + outs.get(i).getLine_num());
        }*/
    }
    public static ArrayList<WrongExample> getWs() {
        return ws;
    }
}