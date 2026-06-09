package frontend.GrammaticalElements.function;

import frontend.Token;

import java.util.ArrayList;

public class FuncFParams {
    /*const string name = "<FuncRParams>";
    Exp* firstExp{};
    vector<Token> commas;
    vector<Exp> exps;*/
    private final String name = "<FuncFParams>";
    private FuncFParam firstFuncFParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(FuncFParam firstFuncFParam, ArrayList<Token> commas, ArrayList<FuncFParam> funcFParams) {
        this.firstFuncFParam = firstFuncFParam;
        this.commas = commas;
        this.funcFParams = funcFParams;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstFuncFParam.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i).toString());
            sb.append(funcFParams.get(i).toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
