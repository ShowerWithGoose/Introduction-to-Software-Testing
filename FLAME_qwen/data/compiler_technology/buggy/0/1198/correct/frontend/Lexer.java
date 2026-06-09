package frontend;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class Lexer {
    private static final HashMap<String, Single> singles = new HashMap<>();
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

        int line_num = 1;
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
                                break;
                            }
                            //System.out.println((char) ch + "!!");
                        }
                        line_num = line_num + 1;
                    } else if ((char) ch == '*') { //多行注释
                        while (true) {
                            ch = f.read();
                            if ((char) ch == '*') {
                                ch = f.read();
                                if((char) ch == '/') {
                                    ch = f.read();
                                    break;
                                }
                            }
                        }
                        //System.out.println("finish");
                    } else { //输出除号
                        //System.out.println("DIV /");
                        x.write("DIV /\n");
                        x.flush();
                    }
                }
                if ((char)ch == '"') { //双引号（字符串）
                    //System.out.print("STRCON \"");
                    x.write("STRCON \"");
                    x.flush();
                    ch = f.read();
                    while ((char)ch != '"') {
                        //System.out.print((char) ch);
                        x.write((char) ch);
                        x.flush();
                        ch = f.read();
                    }
                    //System.out.println('"');
                    x.write("\"\n");
                    x.flush();
                }
                if ((char)ch == '\'') { //单引号（字符）
                    //System.out.print("CHRCON '");
                    x.write("CHRCON '");
                    x.flush();
                    ch = f.read();
                    while ((char)ch != '\'') {
                        //System.out.print((char) ch);
                        x.write((char) ch);
                        x.flush();
                        ch = f.read();
                    }
                    //System.out.println('\'');
                    ch = f.read();
                    if((char)ch == '\'') {
                        x.write(String.valueOf("''\n"));
                        x.flush();
                    } else {
                        x.write( "'\n");
                        x.flush();
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
                    } else {
                        w.write(Integer.toString(line_num));
                        w.write(" a\n");
                        w.flush();
                        //System.out.println(line_num + " a");
                    }
                }
                if ((char) ch == '&') {
                    ch = f.read();
                    if ((char) ch == '&') {
                        //System.out.println("AND &&");
                        x.write("AND &&\n");
                        x.flush();
                    } else {
                        w.write(Integer.toString(line_num));
                        w.write(" a\n");
                        w.flush();
                        //System.out.println(line_num + " a");
                    }
                }
                if((char) ch == '=') {
                    ch = f.read();
                    if ((char) ch == '=') {
                        x.write("EQL ==\n");
                        x.flush();
                        //System.out.println("EQL ==");
                    } else {
                        x.write("ASSIGN =\n");
                        x.flush();
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
                        //System.out.println("NEQ !=");
                    } else {
                        x.write("NOT !\n");
                        x.flush();
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
                        //System.out.println("GEQ >=");
                    } else {
                        x.write("GRE >\n");
                        x.flush();
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
                        //System.out.println("LEQ <=");
                    } else {
                        x.write("LSS <\n");
                        x.flush();
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
                    //System.out.println("PLUS +");
                }
                if ((char) ch == '-') {
                    x.write("MINU -\n");
                    x.flush();
                    //System.out.println("MINU -");
                }
                if ((char) ch == '*') {
                    x.write("MULT *\n");
                    x.flush();
                    //System.out.println("MULT *");
                }
                if ((char) ch == '%') {
                    x.write("MOD %\n");
                    x.flush();
                    //System.out.println("MOD %");
                }
                if ((char) ch == ';') {
                    x.write("SEMICN ;\n");
                    x.flush();
                    //System.out.println("SEMICN ;");
                }
                if ((char) ch == ',') {
                    x.write("COMMA ,\n");
                    x.flush();
                    //System.out.println("COMMA ,");
                }
                if ((char) ch == '(') {
                    x.write("LPARENT (\n");
                    x.flush();
                    //System.out.println("LPARENT (");
                }
                if ((char) ch == ')') {
                    x.write("RPARENT )\n");
                    x.flush();
                    //System.out.println("RPARENT )");
                }
                if ((char) ch == '[') {
                    x.write("LBRACK [\n");
                    x.flush();
                    //System.out.println("LBRACK [");
                }
                if ((char) ch == ']') {
                    x.write("RBRACK ]\n");
                    x.flush();
                    //System.out.println("RBRACK ]");
                }
                if ((char) ch == '{') {
                    x.write("LBRACE {\n");
                    x.flush();
                    //System.out.println("LBRACE {");
                }
                if ((char) ch == '}') {
                    x.write("RBRACE }\n");
                    x.flush();
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
                        //System.out.println(singles.get(String.valueOf(str)).getType()+ " " +String.valueOf(str));
                    } else {
                        x.write("IDENFR " + str + "\n");
                        x.flush();
                        //System.out.println("IDENFR " + str);
                    }
                    if ((char) ch == '\n') {
                        line_num++;
                    }
                    continue;
                }
                ch = f.read();
                if ((char) ch == '\n') {
                    line_num++;
                }
            }
        } catch (IOException e) {
            //System.out.println("wrong!!!");
            e.printStackTrace();
        }
    }
}