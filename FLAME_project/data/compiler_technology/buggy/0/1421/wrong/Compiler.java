import config.Config;
import error.ErrorList;
import token.TokenList;
import utils.IOStream;
import frontend.Lexer;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        if (Config.DEBUG) {
            System.out.println("Compile start!");
            System.out.println(new Config());
        }

        if (Config.INIT) {
            IOStream.init();
        }

        ErrorList el = new ErrorList();

        // token
        Lexer.rawCode = IOStream.readFile();
        TokenList tl = new TokenList();
        Lexer.lexer(tl, el);
        if (Config.LEXER_OUTPUT) {
            IOStream.writeLexer(tl.toString());
        }
        if (Config.DEBUG) {
            System.out.println(tl);
        }


        if (Config.ERROR_OUTPUT) {
            IOStream.writeError(el.toString());
        }
    }

}