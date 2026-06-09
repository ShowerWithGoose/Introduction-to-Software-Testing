import frontend.Lexer;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;


public class Compiler {
    public static void main(String[] args) throws IOException{
        clearContent();
        String filePath = "./testfile.txt";
        String testFile = Files.readString(Paths.get(filePath));
        // 词法分析
        Lexer lexer = Lexer.getInstance();
        lexer.start(testFile);
    }
    public static void clearContent(){
        String errorOutputPath = "error.txt"; // 正确的单词输出文件路径
        String stdOutputPath = "lexer.txt"; // 正确的单词输出文件路径
        try{
            FileWriter errorWriter = new FileWriter(errorOutputPath);
            errorWriter.write("");
            errorWriter.close();
            FileWriter stdWriter = new FileWriter(stdOutputPath);
            stdWriter.write("");
            stdWriter.close();
        }catch (IOException e){}
    }
}
