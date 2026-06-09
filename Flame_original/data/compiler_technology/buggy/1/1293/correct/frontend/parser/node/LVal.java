package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class LVal extends TreeNode {
    private Token identToken = null;
    private Token lToken = null;
    private Token rToken = null;
    private Exp exp = null;

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public LVal(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
