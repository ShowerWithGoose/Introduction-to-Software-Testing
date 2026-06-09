import frontend.Lexer;

import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        String FILENAME = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(FILENAME);
        } catch (FileNotFoundException e) {
            System.err.println("Can't read " + e.getMessage());
            return;
        }
        Lexer lexer = new Lexer(inputStream);
        lexer.LexerOutPut();
    }
}