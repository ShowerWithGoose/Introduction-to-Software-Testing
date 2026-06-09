package frontend.symbol.symbolType;

import java.util.ArrayList;

public class ArraySymbol extends Symbol {
    public int btype; 	// 0 -> int, 1 -> char
    public boolean isCon;
    public int dim;
    public ArrayList<VarSymbol> varList = new ArrayList<>();
}
