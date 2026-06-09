public class Word {
    private final int line;
    private final int column;
    private final String value;
    private final Type type;

    public Word(int line, int column, String value, Type type) {
        this.line = line;
        this.column = column;
        this.value = value;
        this.type = type;
    }


    public int getLine() {
        return line;
    }

    public int getColumn() {
        return column;
    }

    public String getValue() {
        return value;
    }

    public Type getType() {
        return type;
    }

}
