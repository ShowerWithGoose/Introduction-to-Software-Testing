package node;

import frontend.Parser;
import frontend.Token;

public class EqExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.EqExp;
    private EqExp eqExp;
    private Token.TokenType eqOp;
    private RelExp relExp;

    public EqExp(RelExp relExp) {
        this.relExp = relExp;
        this.eqOp = null;
        this.eqExp = null;
    }

    public EqExp(EqExp eqExp, Token.TokenType eqOp, RelExp relExp) {
        this.eqExp = eqExp;
        this.eqOp = eqOp;
        this.relExp = relExp;
    }

    public EqExp getEqExp() {
        return eqExp;
    }

    public Token.TokenType getEqOp() {
        return eqOp;
    }

    public RelExp getRelExp() {
        return relExp;
    }

    public boolean hasEqExp() {
        return eqExp != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (hasEqExp())
            ret.append("\n").append(eqExp).append("\n").append(eqOp);
        ret.append("\n").append(relExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
