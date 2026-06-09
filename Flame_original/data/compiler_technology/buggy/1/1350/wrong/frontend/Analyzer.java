package frontend;

import nonTerminal.CompUnit;

import java.util.ArrayList;

public class Analyzer {
    private CompUnit compUnit;
    private SymbolTable symbolTable;

    public Analyzer(Parser parser) {
        compUnit = parser.getCompUnit();
        symbolTable = new SymbolTable();
        compUnit.analyze(symbolTable);
    }

    public SymbolTable getSymbolTable() {
        return symbolTable;
    }
}