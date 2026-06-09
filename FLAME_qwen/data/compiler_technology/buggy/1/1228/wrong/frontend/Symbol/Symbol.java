package frontend.Symbol;

import frontend.Tree.Ident;

import java.util.ArrayList;

public class Symbol {
    private Ident ident;
    private SymbolType symbolType;
    private int line;
    private int dimension;
    private int depth;
    private boolean isConst;
    private int funcReturnType;
    private ArrayList<Integer> paramTypes;
    private int paramNum;

    public Symbol(Ident ident, SymbolType symbolType, boolean isConst) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.isConst = isConst;
        this.line = ident.getLine();
    }

    public Symbol(Ident ident, SymbolType symbolType, boolean isConst, int dimension) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.line = ident.getLine();
        this.isConst = isConst;
        this.dimension = dimension;
    }

    public Symbol(Ident ident, SymbolType symbolType, int funcReturnType, ArrayList<Integer> paramTypes, int paramNum) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.line = ident.getLine();
        this.funcReturnType = funcReturnType;
        this.paramTypes = paramTypes;
        this.paramNum = paramNum;
    }
}
