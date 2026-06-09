package frontend.semantic;

public class ArraySymbol extends Symbol {
    public ArraySymbol(int tableId, String name, BType btype, boolean isConst) {
        super(tableId, name, btype, isConst);
    }

    @Override
    public Type getType() {
        return Type.ARRAY;
    }
}
