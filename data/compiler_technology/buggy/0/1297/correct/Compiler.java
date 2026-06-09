import Reader.LexicalAnalyzer;
import Reader.TokenStream;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Compiler {
    static String lexerfilePath = "lexer.txt";
    static String errorfilePath = "error.txt";
    public static void main(String[] args) {

        LexicalAnalyzer lexicalAnalyzer = new LexicalAnalyzer();
        TokenStream tokenStream = lexicalAnalyzer.getWordTypes();
        lexerOut(tokenStream);
        // System.out.println(tokenStream);
        // System.err.println(tokenStream.toStringWithErr());
    }

    public static void lexerOut(TokenStream tokenStream) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerfilePath))) {
            writer.write(tokenStream.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorfilePath))) {
            writer.write(tokenStream.toStringWithErr());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}