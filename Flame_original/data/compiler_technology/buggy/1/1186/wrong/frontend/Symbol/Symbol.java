package frontend.Symbol;

public class Symbol {
    String name;
    String type;
    int scope;

    public Symbol(String name, String type, int scope) {
        this.name = name;
        this.type = type;
        this.scope = scope;
    }

    public int getScope() {
        return scope;
    }

    public String toString() {
        return scope + " " + name + " " + type;
    }

    public String getType() {
        return type;
    }
}
