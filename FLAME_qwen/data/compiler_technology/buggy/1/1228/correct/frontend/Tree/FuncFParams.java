package frontend.Tree;

import java.util.ArrayList;

public class FuncFParams {
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    public ArrayList<Integer> getTypes() {
        ArrayList<Integer> paramTypes = new ArrayList<>();
        for (FuncFParam funcFParam : funcFParams) {
            paramTypes.add(funcFParam.getType());
        }
        return paramTypes;
    }
}
