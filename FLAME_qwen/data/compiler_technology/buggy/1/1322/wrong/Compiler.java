import ast.CompUnitNode;
import frontend.MyError;
import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import frontend.Parser;

public class Compiler {
    public static String inputFile = "testfile.txt";
    // public static String outputFile = "lexer.txt";
    public static String errorFile = "error.txt";

    public static List<Token> tokens = new ArrayList<>();
    public static List<MyError> myErrors = new ArrayList<>();

    public static void main(String[] args) {
        // 获取分析结果


        // 创建词法分析器
        Lexer lexer = Lexer.getInstance(tokens,myErrors);
        lexer.initialize(inputFile);
        lexer.tokenize();
        
        // 进行语法分析
        Parser parser = new Parser(tokens, myErrors);
        CompUnitNode compUnitNode = parser.Parse();
        compUnitNode.print();

        myErrors.sort(new Comparator<MyError>() {
            @Override
            public int compare(MyError e1, MyError e2) {
                return Integer.compare(e1.getLineNumber(), e2.getLineNumber());
            }
        });

        File outputFile = new File(Compiler.errorFile);
        try (FileWriter writer = new FileWriter(outputFile, true)) {
            for (MyError myError : myErrors) {
                writer.write(myError.toString());
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
