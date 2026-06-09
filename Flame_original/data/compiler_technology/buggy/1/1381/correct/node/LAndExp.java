package node;

import frontend.Parser;
import frontend.Token;

public class LAndExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.LAndExp;
    private LAndExp lAndExp;
    private EqExp eqExp;

    public LAndExp(LAndExp lAndExp, EqExp eqExp) {
        this.lAndExp = lAndExp;
        this.eqExp = eqExp;
    }

    public LAndExp(EqExp eqExp) {
        this.eqExp = eqExp;
        this.lAndExp = null;
    }

    public LAndExp getLAndExp() {
        return lAndExp;
    }

    public EqExp getEqExp() {
        return eqExp;
    }

    public boolean hasLAndExp() {
        return lAndExp != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (hasLAndExp())
            ret.append("\n").append(lAndExp).append("\n").append(Token.TokenType.AND);
        ret.append("\n").append(eqExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
