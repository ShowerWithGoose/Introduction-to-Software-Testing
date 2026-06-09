package frontend.Symbol;

import java.util.ArrayList;

public class FuncSymbol extends Symbol {
    private int retType; // 0:void; 1:int; 2:char
    private int paramNum;
    private ArrayList<SymType> paramTypeList;

    public FuncSymbol(String id, int tableId, int level, SymType symType, int retType, int paramNum, ArrayList<SymType> paramTypeList) {
        super(id, tableId, level, symType);
        this.retType = retType;
        this.paramNum =paramNum;
        this.paramTypeList = paramTypeList;
    }

    public int getParamNum() {
        return paramNum;
    }

    public int getRetType() {
        return retType;
    }

    public ArrayList<SymType> getParamTypeList() {
        return paramTypeList;
    }
}
