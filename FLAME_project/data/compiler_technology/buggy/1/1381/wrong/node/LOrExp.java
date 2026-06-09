package node;

import frontend.Parser;
import frontend.Token;

public class LOrExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.LOrExp;
    private LOrExp lOrExp;
    private LAndExp landExp;

    public LOrExp(LAndExp landExp) {
        this.landExp = landExp;
        this.lOrExp = null;
    }

    public LOrExp(LOrExp lOrExp, LAndExp landExp) {
        this.lOrExp = lOrExp;
        this.landExp = landExp;
    }

    public LAndExp getLandExp() {
        return landExp;
    }

    public LOrExp getLOrExp() {
        return lOrExp;
    }

    public boolean hasLOrExp() {
        return lOrExp != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (hasLOrExp())
            ret.append("\n").append(lOrExp).append("\n").append(Token.TokenType.OR);
        ret.append("\n").append(landExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
