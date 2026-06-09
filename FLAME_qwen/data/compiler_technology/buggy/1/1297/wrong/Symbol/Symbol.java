package Symbol;

public class Symbol implements SymbolChild {
    private String name;
    private ValueType type;
    private int dim = 1;

    public Symbol(String name, ValueType type, int dim) {
        this.name = name;
        this.type = type;
        this.dim = dim;
    }

    public String getName() {
        return name;
    }

    public ValueType getType() {
        return type;
    }

    public int getDim() {
        return dim;
    }

    public String toString() {
        return dim + " " + name + " : " + type.toString();
    }
}
