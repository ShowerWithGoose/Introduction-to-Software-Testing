package frontend.Symbol;

public enum SymbolType
{
    ConstChar("ConstChar"),
    ConstInt("ConstInt"),
    ConstCharArray("ConstCharArray"),
    ConstIntArray("ConstIntArray"),
    CharVar("Char"),
    IntVar("Int"),
    CharArray("CharArray"),
    IntArray("IntArray"),
    VoidFunc("VoidFunc"),
    CharFunc("CharFunc"),
    IntFunc("IntFunc"),
    ;


    private final String value;

    SymbolType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return this.value;
    }
}
