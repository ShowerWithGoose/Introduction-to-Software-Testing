package symbol;

public class Symbol {
    private SymType symType;
    private String content;

    public Symbol(SymType symType, String content) {
        this.symType = symType;
        this.content = content;
    }

    public SymType getSymType() {
        return symType;
    }

    public String getContent() {
        return content;
    }

    public String toString() {
        return symType.toString() + " " + content + "\n";
    }
}
