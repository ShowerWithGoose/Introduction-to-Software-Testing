package struct;

import token.Token;

import java.util.List;

/* FuncFParams â†’ FuncFParam { ',' FuncFParam } */
public class FuncFParams {
    private final List<FuncFParam> funcFParam;
    private final List<Token> commaToken;

    public FuncFParams(List<FuncFParam> funcFParam, List<Token> commaToken) {
        this.funcFParam = funcFParam;
        this.commaToken = commaToken;
    }

    public List<FuncFParam> getFuncFParam() {
        return funcFParam;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcFParam.get(0).toString());
        for (int i = 1; i < funcFParam.size(); i++) {
            sb.append(commaToken.get(i - 1).toString());
            sb.append(funcFParam.get(i).toString());
        }
        sb.append("<FuncFParams>\n");
        return sb.toString();
    }
}
