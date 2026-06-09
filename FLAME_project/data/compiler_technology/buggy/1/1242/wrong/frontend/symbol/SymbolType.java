package frontend.symbol;

public enum SymbolType {
    ConstChar,
    ConstInt,
    ConstCharArray,
    ConstIntArray,
    Char,
    Int,
    CharArray,
    IntArray,
    VoidFunc,
    CharFunc,
    IntFunc;
    public boolean IsConstLVal() {
        return this == ConstChar || this == ConstInt || this == ConstCharArray || this == ConstIntArray;
    }
}
