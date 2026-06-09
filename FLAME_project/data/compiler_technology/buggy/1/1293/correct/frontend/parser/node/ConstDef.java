package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class ConstDef extends TreeNode {
    private Token identToken = null;
    private Token lToken = null;
    private Token rToken = null;
    private Token assignToken = null;
    private ConstExp constExp = null;
    private ConstInitVal constInitVal = null;

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setAssignToken(Token assignToken) {
        this.assignToken = assignToken;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }
    public ConstDef(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
