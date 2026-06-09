import Fronted.lexer.Lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import Error.ErrorList;
import Fronted.lexer.TokenList;
import Fronted.parser.Parser;
import Fronted.parser.syntax.CompUnit;

public class Compiler {

    private static Output output = Output.getOutput();

    private static String filePath = "testfile.txt";

    private static String lexer = "lexer.txt";

    private static String parser = "parser.txt";

    private static String error = "error.txt";

    public static void main(String[] args) {
        //词法分析
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            int lineNumber = 1; // 行号从1开始
            Lexer lexer = new Lexer();
            while ((line = br.readLine()) != null) {
                lexer.divide(line, lineNumber);
                lineNumber++;
            }
        } catch (IOException e) {
            e.printStackTrace(); // 处理异常
        }
        output.output(lexer, TokenList.getTokenList().toString());
        output.output(error, ErrorList.getErrorList().toString());
        //语法分析
        Parser.compUnit();
        output.output(parser, CompUnit.getCompUnit().toString());
        output.output(error, ErrorList.getErrorList().toString());
    }
}

/*
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt";
        //String filePath = "D:\\idea projects\\CiFaFenXi\\testfile.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            int lineNumber = 1; // 行号从1开始
            Lexer lexer = new Lexer();
            while ((line = br.readLine()) != null) {
                lexer.analyze(line, lineNumber);
                lineNumber++;
            }
            Lexer.right.close();
            Lexer.error.close();
            Lexer.fw1.close();
            Lexer.fw2.close();
        } catch (IOException e) {
            e.printStackTrace(); // 处理异常
        }
    }
}*/


