import AST.CompUnitNode;
import IO.IO;
import Lexer.LexicalAnalyzer;
import Error.*;
import Parser.*;
import Sym.ErrorParser;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;

public class Compiler {

    public static void main(String[] args) throws IOException {

        IO io = new IO();

        errorMessage errorMessage = new errorMessage(io);

        LexicalAnalyzer analyzer = new LexicalAnalyzer(errorMessage);

        analyzer.analyze(io);


        ParserTokens parserTokens = new ParserTokens(analyzer.getTokens(), errorMessage);
        CompUnitNode compUnitNode = parserTokens.parseCompUnit();

        compUnitNode.postOrderTraversal(io);


//        ErrorParser errorParser = new ErrorParser(compUnitNode, io);
//        errorParser.parse();


        errorMessage.printErrors();

        io.closeAll();

    }
}
