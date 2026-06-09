import frontend.*;
import utils.Logger;

import static utils.File.ReadFile;

public class Compiler {
    public static void main(String[] args) {
        String file = "testfile.txt";
        Lexer lexer = new Lexer(ReadFile(file));
        TokenList tokens = lexer.lexer();
        if (Logger.logger.isSuccess()) {
            tokens.print();
        } else {
            Logger.logger.print();
            tokens.print();
        }
    }


}
