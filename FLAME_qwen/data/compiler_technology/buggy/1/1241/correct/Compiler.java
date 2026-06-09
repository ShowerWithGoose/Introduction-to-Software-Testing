import IO.MyWriter;
import IO.Reader;
import common.GComponent;
import common.Token;
import frontend.GrammarAnalysis;
import frontend.Lexer;
import frontend.ast.Node;

import java.io.File;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;

/**
 * The type Compiler.
 *
 * @author
 * @Descriptionï¼š
 * @date
 */
public class Compiler {

    /**
     * The entry point of application.
     *
     * @param args the input arguments
     * @throws IOException the io exception
     */
    public static void main(String[] args) throws IOException {
        MyWriter writer = MyWriter.getWriter();
        ArrayList<String> text = Reader.readCode();
        Lexer lexer = new Lexer(text);
        ArrayList<Token> tokens=lexer.analyze();
        GrammarAnalysis grammarAnalysis = new GrammarAnalysis(tokens);
        Node root = grammarAnalysis.analyze();;


        if(writer.hasError()) {
        writer.printError();
        }
        else {
            //writer.printLexer(tokens);
            writer.printAST(root);
        }

    }
}
