package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class MainFuncDef extends TreeNode {
    private Token intToken = null;
    private Token mainToken = null;
    private Token lToken = null;
    private Token rToken = null;
    private Block block = null;

    public void setIntToken(Token intToken) {
        this.intToken = intToken;
    }

    public void setMainToken(Token mainToken) {
        this.mainToken = mainToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public MainFuncDef(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
