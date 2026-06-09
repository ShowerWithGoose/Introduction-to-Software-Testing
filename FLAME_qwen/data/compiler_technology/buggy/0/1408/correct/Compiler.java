import CompileError.CompileError;
import Front.Lexer;
import IO.Printer;
import IO.Reader;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Reader reader = new Reader("testfile.txt");
        // Reader reader = new Reader("testfile.txt");
        String content = reader.readDoc();
        //String content = reader.readIn();

        ArrayList<CompileError> errors = new ArrayList<>();

        Lexer lexer = new Lexer(content, errors);
        lexer.deal();

        Printer printer = new Printer(errors);
        if (errors.isEmpty())
        {
            printer.printLexerRes("lexer.txt", lexer.getTokens());
        }
        else
        {
            printer.printErrors("error.txt");
        }
    }
}
