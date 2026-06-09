import frontend.*;
import utils.Logger;

import static utils.File.ReadFile;

public class Compiler {
    public static void main(String[] args) {
        String file = "testfile.txt";
        TokenList tokens;

        Lexer lexer = new Lexer(ReadFile(file));
        tokens = lexer.lexer();

        Parser parser = new Parser(tokens);
        Ast ast = parser.parser();

        if (Logger.logger.isSuccess()) {
            ast.print();
        } else {
            Logger.logger.print();
            ast.print();
        }
    }


}
