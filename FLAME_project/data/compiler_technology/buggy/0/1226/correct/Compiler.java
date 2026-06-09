import src.LexicalAnalyzer;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;


public class Compiler {
    public static void main(String[] args) {
        //Step1: Lexical Analysis
        InputStream inputFile = null;
        try {
            inputFile = new FileInputStream("testfile.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        LexicalAnalyzer lexicalAnalyzer = new LexicalAnalyzer();
        lexicalAnalyzer.analyze(inputFile);
    }
}