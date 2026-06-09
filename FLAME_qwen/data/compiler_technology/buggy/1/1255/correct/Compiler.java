import frontend.Lexer;
import frontend.Syntax;
import tree.CompUnit;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        File file = new File("testfile.txt");
        FileWriter fileWriter = new FileWriter("parser.txt");
        FileWriter fileWriter1 = new FileWriter("error.txt");
        lexer.read(file);
        Syntax syntax = new Syntax(lexer,fileWriter,fileWriter1);
        syntax.parseAndOutput();
        fileWriter.close();
        fileWriter1.close();
    }
}