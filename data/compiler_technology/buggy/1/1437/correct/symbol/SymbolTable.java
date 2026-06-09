package symbol;

import java.util.LinkedHashMap;
import java.util.Map;

public class SymbolTable {
    private Map<String, Symbol> symbols;
    private SymbolTable father;
    private int scope;
    private boolean isInFunc;

    public SymbolTable(SymbolTable father, int scope, boolean isInFunc) {
        this.symbols = new LinkedHashMap<>();
        this.father = father;
        this.scope = scope;
        this.isInFunc = isInFunc;
    }

    public Map<String, Symbol> getSymbols() {
        return symbols;
    }

    public SymbolTable getFather() {
        return father;
    }

    public int getScope() {
        return scope;
    }

    public boolean isInFunc() {
        return isInFunc;
    }

    public boolean isExist(String name) {
        return symbols.containsKey(name);
    }

    public void addSymbol(Symbol symbol) {
        symbols.put(symbol.getName(), symbol);
    }
}
