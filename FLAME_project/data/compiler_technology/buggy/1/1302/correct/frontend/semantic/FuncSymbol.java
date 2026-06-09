package frontend.semantic;

import frontend.tree.func.FuncFParam;

import java.util.ArrayList;

public class FuncSymbol extends Symbol {
    private ArrayList<FuncFParam> params = new ArrayList<>();

    public FuncSymbol(int tableId, String name, BType btype, boolean isConst) {
        super(tableId, name, btype, isConst);
    }

    public void setParams(ArrayList<FuncFParam> params) {
        this.params = params;
    }

    public ArrayList<FuncFParam> getParams() {
        return params;
    }

    @Override
    public Type getType() {
        return Type.FUNC;
    }
}
