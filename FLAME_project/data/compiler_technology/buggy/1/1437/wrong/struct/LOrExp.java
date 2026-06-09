package struct;

import token.Token;

import java.util.List;

/* LOrExp â†’ LAndExp { '||' LAndExp } */
public class LOrExp {
    private final List<LAndExp> lAndExp;
    private final List<Token> orToken;

    public LOrExp(List<LAndExp> lAndExp, List<Token> orToken) {
        this.lAndExp = lAndExp;
        this.orToken = orToken;
    }

    public List<LAndExp> getLAndExp() {
        return lAndExp;
    }

    public List<Token> getOrToken() {
        return orToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lAndExp.get(0).toString());
        for (int i = 1; i < lAndExp.size(); i++) {
            sb.append("<LOrExp>\n");
            sb.append(orToken.get(i - 1).toString());
            sb.append(lAndExp.get(i).toString());
        }
        sb.append("<LOrExp>\n");
        return sb.toString();
    }
}
