package frontend.symbol;

import frontend.lexer.Token;
import java.util.ArrayList;
import java.util.HashMap;

public class SymbolTable {
    private final HashMap<String, Symbol> symbolHashMap = new HashMap<>();
    private final ArrayList<Symbol> symbols = new ArrayList<>();
    private final int scope;
    private Symbol funcSymbol = null;
    public enum ScopeType {FUNC, FOR, IF_ELSE, DEFAULT};
    private ScopeType scopeType = ScopeType.DEFAULT;
    private final SymbolTable outerSymbolTable;
    public SymbolTable(int scope, SymbolTable outer) {
        this.scope = scope;
        this.outerSymbolTable = outer;
    }
    public SymbolTable(ScopeType scopeType, int scope, SymbolTable outer) {
        this.scopeType = scopeType;
        this.scope = scope;
        this.outerSymbolTable = outer;
    }
    public void setFuncSymbol(Symbol symbol) {
        this.funcSymbol = symbol;
    }
    public Symbol getFuncSymbol() {
        if (this.funcSymbol != null) return this.funcSymbol;
        if (outerSymbolTable == null) return null;
        return outerSymbolTable.getFuncSymbol();
    }
    public boolean hasOuterScopeOfType(ScopeType scopeType) {
        if (this.scopeType == scopeType) return true;
        if (outerSymbolTable == null) return false;
        return outerSymbolTable.hasOuterScopeOfType(scopeType);
    }
    public void addSymbol(Token token, SymbolType type) {
        Symbol symbol = new Symbol(scope, token, type);
        this.symbols.add(symbol);
        this.symbolHashMap.put(token.getName(), symbol);
    }
    public void addSymbol(Symbol symbol) {
        this.symbols.add(symbol);
        this.symbolHashMap.put(symbol.getName(), symbol);
    }
    public int getScope() {
        return scope;
    }
    public SymbolTable getOuterScope() {
        return outerSymbolTable;
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (Symbol symbol: symbols) {
            result.append(symbol);
        }
        return result.toString();
    }
    public Symbol findSymbol(Token ident, boolean recursive) {
        if (symbolHashMap.get(ident.getName()) != null) {
            return symbolHashMap.get(ident.getName());
        }
        if (recursive && this.outerSymbolTable != null) {
            return outerSymbolTable.findSymbol(ident, true);
        }
        return null;
    }
}
