import config.Config;
import frontend.lex.Lexer;
import frontend.syntax.Ast;
import frontend.syntax.Builder;
import printer.Printer;

import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        BufferedInputStream source = new BufferedInputStream(Config.getSrc());
        BufferedWriter lexer = new BufferedWriter(Config.getLexer());
        BufferedWriter error = new BufferedWriter(Config.getErr());
        BufferedWriter output = new BufferedWriter(Config.getAsm());
        Lexer.lex(source, error);
        //Ast ast = Builder.build();
        Printer.print(lexer);
        lexer.close();
        error.close();
        output.close();
    }
}