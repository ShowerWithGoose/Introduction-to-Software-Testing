import config.Config;
import frontend.Lexer;
import utils.IOUtils;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Config.init();

        String sourceCode = IOUtils.read(Config.fileInPath);

        Lexer.getInstance().analyze(sourceCode);

        if (Config.lexer) {
            Lexer.getInstance().printLexAns();
            Lexer.getInstance().printErrors();
        }
    }
}