package frontend.semantic;

public class VarSymbol extends Symbol {
    public VarSymbol(int tableId, String name, BType btype, boolean isConst) {
        super(tableId, name, btype, isConst);
    }

    @Override
    public Type getType() {
        return Type.VAR;
    }
}
