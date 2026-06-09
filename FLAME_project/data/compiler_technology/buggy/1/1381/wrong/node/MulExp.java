package node;

import frontend.Parser;
import frontend.Token;

public class MulExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.MulExp;
    private MulExp mulExp;
    private Token.TokenType mulOp;
    private UnaryExp unaryExp;

    public MulExp(MulExp mulExp, Token.TokenType mulOp, UnaryExp unaryExp)
    {
        this.mulExp = mulExp;
        this.mulOp = mulOp;
        this.unaryExp = unaryExp;
    }

    public MulExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
        this.mulOp = null;
        this.mulExp = null;
    }

    public MulExp getMulExp() {
        return mulExp;
    }

    public Token.TokenType getMulOp() {
        return mulOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (mulExp != null)
            ret.append("\n").append(mulExp).append("\n").append(mulOp);
        ret.append("\n").append(unaryExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
