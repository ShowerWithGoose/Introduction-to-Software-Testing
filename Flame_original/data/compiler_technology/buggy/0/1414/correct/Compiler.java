import error.Mistake;
import frontend.Config;
import frontend.lexer.Lexer;
import frontend.lexer.Token;

import java.io.File;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer =  new Lexer(Config.source);
        lexer.scan();
        if (Config.emitLexer) {
            File file = new File(Config.LexerOutput);
            try {
                java.io.FileWriter writer = new java.io.FileWriter(file);
                for (Token token : lexer.getTokens()) {
                    writer.write(token.toString() + '\n');
                }
                writer.close();
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
        }
        if (Config.emitError) {
            File file = new File(Config.errorOutput);
            try {
                java.io.FileWriter writer = new java.io.FileWriter(file);
                for (Mistake mistake: lexer.getErrors()) {
                    writer.write(mistake.toString() + '\n');
                }
                writer.close();
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
        }
    }
}