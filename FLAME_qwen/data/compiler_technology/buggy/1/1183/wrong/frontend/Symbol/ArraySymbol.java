package frontend.Symbol;

public class ArraySymbol extends Symbol {
    private int dim;

    public ArraySymbol(String id, int tableId, int level, SymType symType, int dim) {
        super(id, tableId, level, symType);
        this.dim = dim;
    }
}
