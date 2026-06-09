package symbol;


public class Symbol {
    private String name;
    private SymbolType type;
    private int scope;

    public Symbol(String name, SymbolType type, int scope) {
        this.name = name;
        this.type = type;
        this.scope = scope;
    }

    public String getName() {
        return name;
    }

    public SymbolType getType() {
        return type;
    }

    public int getScope() {
        return scope;
    }
}
