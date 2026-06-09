package node;

import frontend.Parser;
import frontend.Token;

public class AddExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.AddExp;
    private AddExp addExp;
    private Token.TokenType addOp;
    private MulExp mulExp;

    public AddExp(MulExp mulExp) {
        this.mulExp = mulExp;
        this.addOp = null;
        this.addExp = null;
    }

    public AddExp(AddExp addExp, Token.TokenType addOp, MulExp mulExp) {
        this.addExp = addExp;
        this.addOp = addOp;
        this.mulExp = mulExp;
    }

    public AddExp getSubAddExp() {
        return addExp;
    }

    public Token.TokenType getAddOp() {
        return addOp;
    }

    public MulExp getMulExp() {
        return mulExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (addExp != null)
            ret.append("\n").append(addExp).append("\n").append(addOp);
        ret.append("\n").append(mulExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
