import frontend.*;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;

public class Compiler {
    public static void main(String[] args) {
        String currentDirectory = System.getProperty("user.dir");
        System.out.println("Current working directory: " + currentDirectory);
        String inputFile = "./hw2/Test/C/testcase1/testfile.txt";
        String outputFile = "lexer.txt";
        String errorFile = "error.txt";

        SourceFile sourceFile = new SourceFile(inputFile);
        Lexer lexer = new Lexer(sourceFile);
        lexer.TokenLize(outputFile, errorFile);

    }
}
