import frontend.error.ErrorProcess;
import frontend.lexer.Lexer;
import frontend.parser.Parser;
import frontend.parser.node.CompUnit;
import frontend.symbol.Analyser;

import java.util.ArrayList;

public class Compiler {
    private Lexer lexer;
    private ErrorProcess errorProcess;
    private Parser parser;
    private Analyser analyser;
    public Compiler() {
        this.errorProcess = new ErrorProcess();
    }
    public static void main(String[] args) {
        Compiler compiler = new Compiler();
        compiler.analyzeLexer();
        compiler.analyzeParser();
        compiler.analyzeSymbol();
    }
    public void analyzeLexer() {
        this.lexer = new Lexer(this.errorProcess);
        lexer.readFile();
        lexer.extractToken();
//        this.outputResult();
    }

    public void analyzeParser() {
        this.parser = new Parser(this.lexer, this.errorProcess);
        parser.buildTree();
//        parser.outputResult();
    }

    public void analyzeSymbol() {
        analyser = new Analyser(this.parser, this.errorProcess);
        CompUnit compUnit = parser.getParent();
    }
}
