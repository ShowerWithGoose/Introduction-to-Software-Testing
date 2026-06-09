package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class FuncFParam extends TreeNode {
    private Token lToken = null;
    private Token rToken = null;
    private Btype btype = null;
    private Token identToken = null;

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setBtype(Btype btype) {
        this.btype = btype;
    }

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public FuncFParam(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
