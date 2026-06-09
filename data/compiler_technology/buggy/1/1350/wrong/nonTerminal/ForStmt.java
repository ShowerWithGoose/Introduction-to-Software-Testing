package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ForStmt {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private int lineCnt;

    public ForStmt() {
        lVal = null;
        assign = null;
        exp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        lVal = new LVal();
        lVal.parser(lexer);
        assign = lexer.now();
        lexer.move();
        exp = new Exp();
        exp.parser(lexer);
        lineCnt = lVal.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        lVal.analyze(symbolTable);
        String type = symbolTable.getType(lVal.getIdentifier().getContent());
        if (type.equals("ConstInt") || type.equals("ConstChar") ||
                type.equals("ConstCharArray") || type.equals("ConstIntArray")) {
            symbolTable.addError(lVal.getLineCnt() + " h");
        }
        exp.analyze(symbolTable);
    }
}
