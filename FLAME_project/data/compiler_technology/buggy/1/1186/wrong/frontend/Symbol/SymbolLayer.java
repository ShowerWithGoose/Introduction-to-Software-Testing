package frontend.Symbol;

import java.util.HashMap;
import java.util.Map;

public class SymbolLayer {
    private int scopeNum;
    private Map<String, Symbol> symbols;

    public SymbolLayer(int scopeNum) {
        this.scopeNum = scopeNum;
        this.symbols = new HashMap<>();
    }

    public int getNum() {
        return scopeNum;
    }

    public void addSymbol(String name, Symbol symbol) {
        symbols.put(name, symbol);
    }

    public Map<String, Symbol> getSymbols() {
        return symbols;
    }
}
