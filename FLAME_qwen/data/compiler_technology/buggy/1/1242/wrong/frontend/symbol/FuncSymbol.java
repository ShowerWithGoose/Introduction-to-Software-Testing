package frontend.symbol;

import java.util.ArrayList;

public class FuncSymbol extends Symbol{
    private  int paramsNumber;

    private ArrayList<SymbolType> paramsType;

    public FuncSymbol(int scope, String name, SymbolType type,int line,int paramsNumber,ArrayList<SymbolType> paramsType) {
        super(scope, name, type,line);
        this.paramsNumber = paramsNumber;
        this.paramsType = paramsType;
    }


    public int GetParamsNumber() {
        return paramsNumber;
    }

    public ArrayList<SymbolType> GetparamsType() {
        return paramsType;
    }

}
