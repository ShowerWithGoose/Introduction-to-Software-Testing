package node;

public class Ident {
    public enum Type {
        CONST, VAR, FUNC
    }

    private String name;
    private Type type;

    public Ident(String name, Type type) {
        this.name = name;
        this.type = type;
    }

    public String toString() {
        return "<" + type + "> " + name;
    }
}
