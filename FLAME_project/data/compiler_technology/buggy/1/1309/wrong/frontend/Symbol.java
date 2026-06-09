package frontend;

public class Symbol {
    SymbolType type;
    String value;
    int lineNum;

    public Symbol(SymbolType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public SymbolType getType() {
        return this.type;
    }

    public String getValue() {
        return this.value;
    }

    public int getLineNum() { return this.lineNum; }

    public void print() {
        System.out.println(this.type + " " + this.value);
        }
}
