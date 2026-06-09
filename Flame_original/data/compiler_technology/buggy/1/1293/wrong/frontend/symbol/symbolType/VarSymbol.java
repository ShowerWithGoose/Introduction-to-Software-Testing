package frontend.symbol.symbolType;

public class VarSymbol extends Symbol{
    public int val;
    public int reg;
    public int btype; 	// 0 -> int, 1 -> char
    public boolean isCon;
}
