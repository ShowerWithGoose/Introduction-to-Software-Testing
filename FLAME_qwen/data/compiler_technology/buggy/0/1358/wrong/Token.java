public class Token {
    private Symbol symbol;
    private String value;
    private int line;

    public Token(Symbol symbol, String value, int line) {
        this.symbol = symbol;
        this.value = value;
        this.line = line;
    }


    public Symbol getSymbol() {
        return symbol;
    }

    public String getValue() {
        return value;
    }

    public int getLine() {
        return this.line;
    }


    @Override
    public String toString() {
        return this.symbol + " " + this.value;
    }
}