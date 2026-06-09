package frontend.Symbol;

import frontend.Tree.Ident;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Symbol {
    private Ident ident;
    private SymbolType symbolType;
    private int line;
    private boolean isArray;
    private int depth;
    private boolean isConst;
    private int funcReturnType;   //0是char，1是int，2是void
    private ArrayList<Integer> paramTypes;  //0是char，1是charArray，2是int，3是intArray
    private int paramNum = 0;
    private int id;

    public Symbol(Ident ident, SymbolType symbolType, boolean isConst) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.isConst = isConst;
        this.line = ident.getLine();
    }

    public Symbol(Ident ident, SymbolType symbolType, boolean isConst, boolean isArray, int id) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.line = ident.getLine();
        this.isConst = isConst;
        this.isArray = isArray;
        this.id = id;
    }

    public Symbol(Ident ident, SymbolType symbolType, int funcReturnType, ArrayList<Integer> paramTypes, int id) {
        this.ident = ident;
        this.symbolType = symbolType;
        this.line = ident.getLine();
        this.funcReturnType = funcReturnType;
        this.paramTypes = paramTypes;
        if (paramTypes != null) {
            this.paramNum = paramTypes.size();
        }
        this.id = id;
    }

    public String getIdent() {
        return ident.getIdent();
    }

    public void print(BufferedWriter writer) throws IOException {
        writer.write(id + " " + ident.getIdent() + " " + symbolType + "\n");
        //System.out.println(id+" "+ident.getIdent()+" "+symbolType);
    }

    public boolean isConst() {
        return isConst;
    }

    public int getParamNum() {
        return paramNum;
    }

    public int getType() {
        if (symbolType == SymbolType.Char || symbolType == SymbolType.ConstChar || symbolType == SymbolType.CharFunc) {
            return 0;
        } else if (symbolType == SymbolType.CharArray || symbolType == SymbolType.ConstCharArray) {
            return 1;
        } else if (symbolType == SymbolType.Int || symbolType == SymbolType.ConstInt || symbolType == SymbolType.IntFunc) {
            return 2;
        } else {
            return 3;
        }
    }

    public ArrayList<Integer> getParamTypes() {
        return paramTypes;
    }
}
