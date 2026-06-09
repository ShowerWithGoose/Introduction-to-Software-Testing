import frontend.Lexer;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


public class Compiler {
    public static void main(String[] args) {
        Path path = Paths.get("testfile.txt");
        try {
            String inputSource = Files.readString(path);
            Lexer lexer = new Lexer(inputSource);
            PrintWriter lexerOutput = new PrintWriter("lexer.txt");
            PrintWriter errorOutput = new PrintWriter("error.txt");
            while (lexer.next() != -1) {
                String tokenType = lexer.getTokenType();
                String tokenValue = lexer.getToken();
                lexerOutput.println(tokenType + " " + tokenValue);
            }
            lexerOutput.close();
            errorOutput.close();

            //System.out.println(inputSource);

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}