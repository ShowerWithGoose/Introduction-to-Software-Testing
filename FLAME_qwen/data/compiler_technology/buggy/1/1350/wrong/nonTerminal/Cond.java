package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Cond {
    private LOrExp lOrExp;
    private int lineCnt;

    public Cond() {
        lOrExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        lOrExp = new LOrExp();
        lOrExp.parser(lexer);
        lineCnt = lOrExp.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        lOrExp.analyze(symbolTable);
    }
}
