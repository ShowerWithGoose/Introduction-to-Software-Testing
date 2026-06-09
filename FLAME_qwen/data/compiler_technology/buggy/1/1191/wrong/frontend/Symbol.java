package frontend;

public class Symbol {
    private String name;
    private String type;
    private int scope;
    private int dimension;
    private Symbol_FuncFParams symbol_funcFParams;

    public Symbol(String name, String type, int scope, int dimension) {
        this.name = name;
        this.type = type;
        this.scope = scope;
        this.dimension = dimension;
        this.symbol_funcFParams = new Symbol_FuncFParams();
    }

    public void setSymbol_funcFParams(Symbol_FuncFParams symbol_funcFParams) {
        this.symbol_funcFParams = symbol_funcFParams;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getScope() {
        return scope;
    }

    public int getDimension() {
        return dimension;
    }

    public Symbol_FuncFParams getSymbol_funcFParams() {
        return symbol_funcFParams;
    }
}
