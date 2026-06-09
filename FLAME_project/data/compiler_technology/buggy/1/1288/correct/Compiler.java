import frontend.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

public class Compiler {
    public static void main(String[] args) {
        int arg = 1;    //0:词法分析输出打开
        int arg2 = 0;   //0:语法分析输出打开
        int arg3 = 0;   //0:符号表建立输出打开

        String filePath = "testfile.txt";
        Readfile readfile = new Readfile(filePath);
        String srccode = readfile.read();

        HashMap<String, Type> keywords = new HashMap<>();   //保留字表
        initKeywords(keywords);
        TreeMap<Integer, ArrayList<MyError>> errors = new TreeMap<>();  //错误表
        boolean isErr = false;

        Lexer lexer = Lexer.getInstance(srccode, keywords, errors);
        Parser parser = new Parser(lexer, arg2, errors);
        //parser.parseCompUnit();
        isErr = lexer.isError() || parser.isErr();

        if (arg == 0) {
            FileWriter output = null;
            if (isErr) {
                try {
                    output = new FileWriter("error.txt");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                BufferedWriter writer = new BufferedWriter(output);

                errors.forEach((k, v) -> {
                    v.forEach(error -> {
                        try {
                            writer.write(error.getLine() + " " + error.getMsg() + "\n");
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    });
                });

                try {
                    writer.flush();
                    writer.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            } else {
                try {
                    output = new FileWriter("lexer.txt");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                BufferedWriter writer = new BufferedWriter(output);
                while (lexer.notEnd()) {
                    try {
                        Token token = lexer.now();
                        lexer.next();
                        writer.write(token.getType() + " " + token.getName() + "\n");
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
                try {
                    writer.flush();
                    writer.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        if (arg2 == 0) {
            if (isErr) {
                FileWriter output = null;
                try {
                    output = new FileWriter("error.txt");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                BufferedWriter writer = new BufferedWriter(output);

                errors.forEach((k, v) -> {
                    v.forEach(error -> {
                        try {
                            writer.write(error.getLine() + " " + error.getMsg() + "\n");
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    });
                });


                try {
                    writer.flush();
                    writer.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            } else {
                FileWriter output = null;
                try {
                    output = new FileWriter("parser.txt");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                BufferedWriter writer = new BufferedWriter(output);
                try {
                    writer.write(parser.getOut().toString());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                try {
                    writer.flush();
                    writer.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

    }

    public static void initKeywords(HashMap<String, Type> keywords) {
        keywords.put("const", Type.CONSTTK);
        keywords.put("int", Type.INTTK);
        keywords.put("char", Type.CHARTK);
        keywords.put("void", Type.VOIDTK);
        keywords.put("main", Type.MAINTK);
        keywords.put("if", Type.IFTK);
        keywords.put("else", Type.ELSETK);
        keywords.put("for", Type.FORTK);
        keywords.put("printf", Type.PRINTFTK);
        keywords.put("return", Type.RETURNTK);
        keywords.put("break", Type.BREAKTK);
        keywords.put("continue", Type.CONTINUETK);
        keywords.put("!", Type.NOT);
        keywords.put("&&", Type.AND);
        keywords.put("||", Type.OR);
        keywords.put("getint", Type.GETINTTK);
        keywords.put("getchar", Type.GETCHARTK);
        keywords.put("+", Type.PLUS);
        keywords.put("-", Type.MINU);
        keywords.put("*", Type.MULT);
        keywords.put("/", Type.DIV);
        keywords.put("%", Type.MOD);
        keywords.put("<", Type.LSS);
        keywords.put("<=", Type.LEQ);
        keywords.put(">", Type.GRE);
        keywords.put(">=", Type.GEQ);
        keywords.put("==", Type.EQL);
        keywords.put("!=", Type.NEQ);
        keywords.put("=", Type.ASSIGN);
        keywords.put(";", Type.SEMICN);
        keywords.put(",", Type.COMMA);
        keywords.put("(", Type.LPARENT);
        keywords.put(")", Type.RPARENT);
        keywords.put("[", Type.LBRACK);
        keywords.put("]", Type.RBRACK);
        keywords.put("{", Type.LBRACE);
        keywords.put("}", Type.RBRACE);
    }
}