import frontend.Lexer;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        File file = new File("testfile.txt");
        FileWriter fileWriter = new FileWriter("lexer.txt");
        FileWriter fileWriter1 = new FileWriter("error.txt");
        lexer.read(file,fileWriter,fileWriter1);
        lexer.compile();
        lexer.output();
        fileWriter.close();
        fileWriter1.close();
    }
}