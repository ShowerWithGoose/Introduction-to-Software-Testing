import frontend.*;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class Compiler {
    public static void main(String[] args) throws IOException{
        clearContent();
        TokenType.makeMap();
        String filePath = "./testfile.txt";
        String testFile = Files.readString(Paths.get(filePath));
        // 词法分析
        Lexer lexer = Lexer.getInstance();
        lexer.start(testFile);
        // 语法分析
        Praser praser = Praser.getInstance();
        praser.start(lexer.getTokenList(), lexer.getErrorList());
    }
    public static void clearContent(){
        String lexerOutputPath = "lexer.txt";
        String errorOutputPath = "error.txt"; // 正确的单词输出文件路径
        String parserOutputPath = "parser.txt"; // 正确的单词输出文件路径
        try{
            FileWriter errorWriter = new FileWriter(errorOutputPath);
            errorWriter.write("");
            errorWriter.close();
            FileWriter  praserWriter = new FileWriter(parserOutputPath);
            praserWriter.write("");
            praserWriter.close();
            FileWriter lexerWriter = new FileWriter(lexerOutputPath);
            lexerWriter.write("");
            lexerWriter.close();
        }catch (IOException e){}
    }
}
