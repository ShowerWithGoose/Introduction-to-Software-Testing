package node;

import frontend.Parser;
import frontend.Token;

public class Stmt {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Stmt;
    private Token.TokenType type;
    private Exp exp;
    private Block block;

    public Stmt() {
        this.type = null;
        this.exp = null;
        this.block = null;
    }

    public Stmt(Exp exp) {
        this.exp = exp;
        this.type = null;
        this.block = null;
    }

    public Stmt(Block block) {
        this.block = block;
        this.type = null;
        this.exp = null;
    }

    public Stmt(Token.TokenType tokenType) {
        this.type = tokenType;
        this.exp = null;
        this.block = null;
    }

    public Parser.SyntaxType getNodeType() {
        return nodeType;
    }

    public Token.TokenType getType() {
        return type;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (type != null) return this.toString();
        else if (exp != null) ret.append("\n").append(exp);
        else if (block != null) ret.append("\n").append(block);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
