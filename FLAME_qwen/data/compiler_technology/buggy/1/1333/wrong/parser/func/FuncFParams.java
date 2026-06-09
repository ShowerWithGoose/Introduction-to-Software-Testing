package parser.func;

import java.util.ArrayList;

public class FuncFParams {
    private final ArrayList<FuncFParam> funcFParams;

    public FuncFParams() {
        this.funcFParams = new ArrayList<>();
    }

    public void addFuncFParam(FuncFParam funcFParam) {
        this.funcFParams.add(funcFParam);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.funcFParams.get(0).toString());
        for (int i = 1; i < this.funcFParams.size(); i++) {
            str.append("COMMA ,\n");
            str.append(this.funcFParams.get(i).toString());
        }
        str.append("<FuncFParams>\n");
        return str.toString();
    }
}
