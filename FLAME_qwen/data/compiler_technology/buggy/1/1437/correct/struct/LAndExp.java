package struct;

import token.Token;

import java.util.List;

/* LAndExp â†’ EqExp { '&&' EqExp } */
public class LAndExp {
    private final List<EqExp> eqExp;
    private final List<Token> andToken;

    public LAndExp(List<EqExp> eqExp, List<Token> andToken) {
        this.eqExp = eqExp;
        this.andToken = andToken;
    }

    public List<EqExp> getEqExp() {
        return eqExp;
    }

    public List<Token> getAndToken() {
        return andToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(eqExp.get(0).toString());
        for (int i = 1; i < eqExp.size(); i++) {
            sb.append("<LAndExp>\n");
            sb.append(andToken.get(i - 1).toString());
            sb.append(eqExp.get(i).toString());
        }
        sb.append("<LAndExp>\n");
        return sb.toString();
    }
}
