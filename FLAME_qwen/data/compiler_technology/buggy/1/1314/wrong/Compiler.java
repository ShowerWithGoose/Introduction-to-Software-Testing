
import frontend.ErrorHandler.ErrorHandler;
import frontend.ErrorHandler.Error;
import frontend.lexer.LexicalAnalyzer;
import frontend.lexer.Preprocess;
import frontend.lexer.Token;
import frontend.parser.ParseUnit;
import frontend.parser.Parser;
import frontend.symbols.Symbol;
import frontend.symbols.SymbolTable;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path = "testfile.txt"; // 指定文件路径
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = reader.readLine()) != null) {
                contentBuilder.append(line).append("\n"); // 读取每一行并追加换行符
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
        Preprocess preprocess = new Preprocess(contentBuilder);
        StringBuilder afterPreProcess = preprocess.process();
        // 将读取的内容转换为String
        String content = afterPreProcess.toString();
        //System.out.println(content);
        LexicalAnalyzer lexicalAnalyzer = new LexicalAnalyzer(content);
        lexicalAnalyzer.parse();
        ArrayList<Token> tokens = lexicalAnalyzer.getTokens();
        Parser parser = new Parser(tokens);

//        System.out.print(parser.getSymbolTable().toString());
//        ErrorHandler.getInstance().sortErrorsByLine();
//        ErrorHandler.getInstance().printErrors();
//        System.out.println(parser.parseCompUnit().toString());
//        parser.parseCompUnit();
//        ErrorHandler.getInstance().sortErrorsByLine();
//        ErrorHandler.getInstance().printErrors();
        //System.out.println(parser.getErrors().toString());
        try {
            ParseUnit parseUnit=parser.parseCompUnit();
            //SymbolTable symbolTable = parser.getSymbolTable();
            if (!ErrorHandler.getInstance().getErrors().isEmpty()) {
                ErrorHandler.getInstance().sortErrorsByLine();
                FileWriter fileWriter = new FileWriter("error.txt", false); // true 表示追加写入
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                for (Error error : ErrorHandler.getInstance().getErrors()) {
                    bufferedWriter.write(error.toString());
                    bufferedWriter.newLine(); // 写入换行符
                }
                bufferedWriter.close();
            } else {
                FileWriter fileWriter = new FileWriter("parser.txt", false); // true 表示追加写入
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write(parseUnit.toString());
                bufferedWriter.close();
            }


        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        // 使用LexicalAnalyzer处理读取的内容
//        LexicalAnalyzer analyzer = new LexicalAnalyzer(content);
//        try {
//            ArrayList<HashMap<Word, String>> result = analyzer.parse();
//            // 输出或处理结果
//        } catch (Exception e) {
//            System.err.println("Error during lexical analysis: " + e.getMessage());
//        }
    }
}
