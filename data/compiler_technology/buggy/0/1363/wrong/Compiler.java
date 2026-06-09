
import front_end.lexer.Lexer;
import front_end.lexer.Token;
import front_end.lexer.TokenStream;
import utils.Printer;


import java.io.FileInputStream;
import java.io.PushbackInputStream;

public class Compiler {
    public static void main(String[] args) throws Exception {

        PushbackInputStream input = new PushbackInputStream(new FileInputStream("testfile.txt"), 16);
        Printer.init();
        // token analyse
        Lexer lexer = new Lexer(input);
        TokenStream tokenStream = lexer.getTokenStream();
        Token token = tokenStream.read();
        while (token != null) {
           Printer.printToken(token);
           token = tokenStream.read();
        }

        Printer.printAllErrorMsg();
        // close all streams
        input.close();
    }
}
