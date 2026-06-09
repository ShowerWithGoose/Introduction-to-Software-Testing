package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;

import java.util.ArrayList;

public class ConstExp {
    private AddExp addExp;
    private int lineCnt;

    public ConstExp() {
        addExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        addExp = new AddExp();
        addExp.parser(lexer);
        lineCnt = addExp.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        addExp.analyze(symbolTable);
    }
}
