package struct;

import token.Token;

import java.util.List;

/* FuncRParams â†’ Exp { ',' Exp } */
public class FuncRParams {
    private final List<Exp> exp;
    private final List<Token> commaToken;

    public FuncRParams(List<Exp> exp, List<Token> commaToken) {
        this.exp = exp;
        this.commaToken = commaToken;
    }

    public List<Exp> getExp() {
        return exp;
    }

    public List<Token> getCommaToken() {
        return commaToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.get(0).toString());
        for (int i = 1; i < exp.size(); i++) {
            sb.append(commaToken.get(i - 1).toString());
            sb.append(exp.get(i).toString());
        }
        sb.append("<FuncRParams>\n");
        return sb.toString();
    }
}
