import error.ErrorCode;
import frontend.Parser;
import node.SyntaxTreeNode;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Map;

public class Compiler {
    public static void main(String[] args) {
        String sourceFile = "testfile.txt";
        String lexerOutputFile = "parser.txt";
        String errorOutputFile = "error.txt";

        try {
            frontend.Lexer lexer = new frontend.Lexer(sourceFile);
            lexer.tokenize();
            frontend.Parser parser = new Parser(lexer);
            SyntaxTreeNode synTree = parser.parseCompUnit();

            PrintStream lexerOutputStream = new PrintStream(new FileOutputStream(lexerOutputFile));
            PrintStream errorOutputStream = new PrintStream(new FileOutputStream(errorOutputFile));

            synTree.print(lexerOutputStream);

            Map<Integer,ErrorCode> errors = lexer.getErrors();
            errors.putAll(parser.getErrors());

            for (ErrorCode error : errors.values()) {
                errorOutputStream.println(error.toString());
            }
            lexerOutputStream.close();
            errorOutputStream.close();
        } catch (FileNotFoundException e) {
            System.err.println("Error: Source file not found.");
        } catch (IOException e) {
            System.err.println("Error: I/O exception occurred.");
        }
    }
}