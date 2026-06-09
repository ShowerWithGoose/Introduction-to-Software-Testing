package frontend.Symbol;

public class Symbol {
    private String id;
    private int tableId;
    private int level;
    private SymType symType;
    private boolean isConst;


    public Symbol(String id, int tableId, int level, SymType symType) {
        this.id = id;
        this.tableId = tableId;
        this.level = level;
        this.symType = symType;
        isConst = symType == SymType.ConstChar || symType == SymType.ConstInt || symType == SymType.ConstCharArray ||
                symType == SymType.ConstIntArray;
    }

    public String getId() {
        return id;
    }

    public boolean isConst() {
        return isConst;
    }

    public boolean isArray() {
        return symType == SymType.CharArray || symType == SymType.ConstCharArray || symType == SymType.IntArray || symType == SymType.ConstIntArray;
    }

    public SymType getSymType() {
        return symType;
    }

    @Override
    public String toString() {
        return Integer.toString(tableId) + ' ' + id + ' ' + symType;
    }
}
