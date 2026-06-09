package node;

import frontend.Parser;
import frontend.Token;

public class RelExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.RelExp;
    private RelExp relExp;
    private Token.TokenType relOp;
    private AddExp addExp;

    public RelExp(RelExp relExp, Token.TokenType relOp, AddExp addExp) {
        this.relExp = relExp;
        this.relOp = relOp;
        this.addExp = addExp;
    }

    public RelExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public RelExp getRelExp() {
        return relExp;
    }

    public Token.TokenType getRelOp() {
        return relOp;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    public boolean hasRelExp() {
        return relExp != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (hasRelExp())
            ret.append("\n").append(relExp).append("\n").append(relOp);
        ret.append("\n").append(addExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
