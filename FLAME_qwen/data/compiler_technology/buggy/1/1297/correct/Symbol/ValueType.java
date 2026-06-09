package Symbol;

public enum ValueType {
    INT("Int"),
    CHAR("Char"),
    VOID("Void"),
    INTARRAY("IntArray"),
    CHARARRAY("CharArray");

    public String toString()
    {
        return value;
    }

    private String value;

    ValueType(String value) {
        this.value = value;
    }

    public Boolean isArray()
    {
        if (this == INTARRAY || this == CHARARRAY)
        {
            return Boolean.TRUE;
        }
        return Boolean.FALSE;
    }
}
