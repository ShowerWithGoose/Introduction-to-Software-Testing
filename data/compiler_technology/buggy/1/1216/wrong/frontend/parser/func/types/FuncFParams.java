package frontend.parser.func.types;

import frontend.lexer.Token;

import java.util.ArrayList;

public class FuncFParams {
    private final FuncFParam firstParam;
    private final ArrayList<FuncFParam> params = new ArrayList<>();
    private final ArrayList<Token> seps = new ArrayList<>();
    public FuncFParams(FuncFParam firstParam) {
        this.firstParam = firstParam;
    }
    public void addFParam(Token sep, FuncFParam param) {
        this.params.add(param);
        this.seps.add(sep);
    }
    public ArrayList<FuncFParam> getParams() {
        return this.params;
    }
    public FuncFParam getFirstParam() {
        return firstParam;
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(firstParam);
        for (int i = 0; i < params.size(); i++) {
            res.append(seps.get(i));
            res.append(params.get(i));
        }
        res.append("<FuncFParams>\n");
        return res.toString();
    }
}
