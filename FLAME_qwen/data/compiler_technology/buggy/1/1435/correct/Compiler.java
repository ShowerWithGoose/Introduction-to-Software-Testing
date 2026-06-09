import frontend.Error.Error;
import frontend.Error.ErrorList;
import frontend.Lexer.Lexer;
import frontend.Lexer.Token;
import frontend.Parser.Parser;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;

public class Compiler {
    private static ArrayList<Token> tokenList;
    private static ArrayList<Error> errorList;

    public static void main(String[] args) throws IOException{
        String testFilePath = "testfile.txt";
        try {
            String fileContent = new String(Files.readAllBytes(Paths.get(testFilePath)));

            Lexer lexer = new Lexer(fileContent);
            lexer.doLexer();
            tokenList = lexer.getTokenList().getTokenList();
            errorList = lexer.getErrorList();
            ErrorList.addErrorList(errorList);

//            test1(tokenList, errorList);

            Parser parser = new Parser(tokenList);
            parser.doParser();
//            parser.print();
            parser.print_tree_to_file();

//            parser.print_to_Sym();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void test1(ArrayList<Token> tokenList, ArrayList<String> errorList){
        String lexerFilePath = "lexer.txt";
        String errorFilePath = "error.txt";

        if(errorList.isEmpty()){
            try (FileWriter fileWriter = new FileWriter(lexerFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                for (Token token : tokenList) {
                    printWriter.println(token.getType() + " " + token.getValue()); // 将每行内容写入文件
                }
                System.out.println("内容已成功写入到 " + lexerFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
        else{
            try (FileWriter fileWriter = new FileWriter(errorFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                for (String error: errorList) {
                    printWriter.println(error); // 将每行内容写入文件
                }
                System.out.println("内容已成功写入到 " + errorFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
    }
}