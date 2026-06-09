package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class FuncDef extends TreeNode {
    private FuncType funcType = null;
    private Token identToken = null;
    private Token lToken = null;
    private FuncFParams funcFParams = null;
    private Token rToken = null;
    private Block block = null;

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public FuncDef(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
