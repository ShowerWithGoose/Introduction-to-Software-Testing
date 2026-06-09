import frontend.Lexer;
import frontend.MyError;
import frontend.Token;
import frontend.Type;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt";
        Readfile readfile = new Readfile(filePath);
        String srccode = readfile.read();

        HashMap<String, Type> keywords = new HashMap<>();
        initKeywords(keywords);


        Lexer lexer = Lexer.getInstance(srccode, keywords);

        FileWriter output = null;
        if (lexer.isError()) {
            try {
                output = new FileWriter("error.txt");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            BufferedWriter writer = new BufferedWriter(output);
            for (MyError error : lexer.getErrors()) {
                try {
                    writer.write(error.getLine() + " " + error.getMsg() + "\n");
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