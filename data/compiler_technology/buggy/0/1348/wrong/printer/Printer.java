package printer;

import config.Config;
import frontend.lex.Token;
import frontend.lex.TokenList;

import java.io.BufferedWriter;
import java.io.IOException;

public class Printer {
    public static void print(BufferedWriter lexerOut) throws IOException {
        if (Config.printLex) {
            for (Token token : TokenList.tokens) {
                lexerOut.write(token.type + " " + token.content + "\n");
            }
        }
    }
}
