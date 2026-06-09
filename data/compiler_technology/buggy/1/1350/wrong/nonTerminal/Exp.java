package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Exp {
    public enum ExpType {
        VAR, INTARR, CHARARR
    }

    private AddExp addExp;
    private int lineCnt;
    private ExpType expType;

    public Exp() {
        addExp = null;
        lineCnt = 0;
        expType = null;
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

    public void analyzeExpType(SymbolTable symbolTable) {
        if (addExp.getMulExp() == null) {
            expType = ExpType.VAR;
            return;
        }
        MulExp mulExp = addExp.getMulExp();
        if (mulExp.getUnaryExp() == null) {
            expType = ExpType.VAR;
            return;
        }
        UnaryExp unaryExp = mulExp.getUnaryExp();
        if (unaryExp.getPrimaryExp() == null) {
            expType = ExpType.VAR;
            return;
        }
        PrimaryExp primaryExp = unaryExp.getPrimaryExp();
        if (primaryExp.getLVal() == null) {
            expType = ExpType.VAR;
            return;
        }
        LVal lVal = primaryExp.getLVal();
        if (lVal.getLbrack() != null) {
            expType = ExpType.VAR;
            return;
        }
        String name = lVal.getIdentifier().getContent();
        if (symbolTable.getType(name).contains("CharArray")) {
            expType = ExpType.CHARARR;
        } else if (symbolTable.getType(name).contains("IntArray")) {
            expType = ExpType.INTARR;
        } else {
            expType = ExpType.VAR;
        }
    }

    public ExpType getExpType() {
        return expType;
    }
}
