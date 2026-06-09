import config.Config;
import frontend.lexer.Lexer;

import java.io.IOException;

public class Compiler {

    public static void main(String[] args) {
        Config.setInputFilePath("testfile.txt");
        Config.setOutputFilePath("lexer.txt");
        Config.setErrorFilePath("error.txt");
        Config.setLexOption(true);

        Lexer lexer = Lexer.getInstance();
        try {
            lexer.run();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}