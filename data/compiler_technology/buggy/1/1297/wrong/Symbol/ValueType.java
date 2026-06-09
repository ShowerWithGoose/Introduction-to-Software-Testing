package Symbol;

public enum ValueType {
    INT("int"),
    CHAR("char"),
    VOID("void");

    private String value;

    ValueType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
