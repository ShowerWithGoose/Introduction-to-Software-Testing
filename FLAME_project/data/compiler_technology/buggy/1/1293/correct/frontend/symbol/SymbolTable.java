package frontend.symbol;

import frontend.symbol.symbolType.Symbol;

import java.util.HashMap;

public class SymbolTable {
    public int id;
    public int fatherId;
    public int layer;
    public HashMap<String, Symbol> directory = new HashMap<>();
}
