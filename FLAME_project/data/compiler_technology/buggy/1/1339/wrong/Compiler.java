import frontend.AST.AST;
import util.Logger;
import frontend.Lexer;
import frontend.Parser;
import frontend.TokenList;

import java.io.*;

import static util.File.readFile;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer(readFile("testfile.txt"));
        TokenList tokens = lexer.getTokenList();

        Parser parser = new Parser(tokens);
        parser.parser();

        if (Logger.logger.hasError()) {
            Logger.logger.print();
        } else {
            //tokens.print();
            AST.ast.print();
        }
    }
}
