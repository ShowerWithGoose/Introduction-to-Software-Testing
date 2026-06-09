package symbol;


public class VarSym extends Symbol {
    private String content;
    private boolean isConst;
    private boolean isArray;

    public VarSym(String name, SymbolType type, int scope, String content, boolean isConst, boolean isArray) {
        super(name, type, scope);
        this.content = content;
        this.isConst = isConst;
        this.isArray = isArray;
    }

    public String getContent() {
        return content;
    }

    public boolean isConst() {
        return isConst;
    }

    public boolean isArray() {
        return isArray;
    }
}
