package frontend.symbol.symbolType;

import java.util.ArrayList;

public class FuncSymbol extends Symbol{
    public int type;    // 0 -> void  1 -> int  2 -> char
    public int retype;
    public int paramNum;
    public int reg;
    public ArrayList<Symbol> paramList = new ArrayList<>();
}
