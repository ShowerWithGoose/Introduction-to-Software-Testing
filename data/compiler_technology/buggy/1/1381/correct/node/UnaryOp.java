package node;

import frontend.Parser;
import frontend.Token;

public class UnaryOp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.UnaryOp;
    private Token.TokenType op;

    public UnaryOp(Token.TokenType op) {
        this.op = op;
    }

    public Token.TokenType getOp() {
        return op;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(op);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
