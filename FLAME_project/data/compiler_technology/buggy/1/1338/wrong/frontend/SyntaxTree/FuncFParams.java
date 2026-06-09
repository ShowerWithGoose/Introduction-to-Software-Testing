package frontend.SyntaxTree;

import java.util.ArrayList;

public class FuncFParams {
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams() {
        this.funcFParams = new ArrayList<>();
    }

    public void addFuncFParam(FuncFParam funcFParam) {
        this.funcFParams.add(funcFParam);
    }
}
