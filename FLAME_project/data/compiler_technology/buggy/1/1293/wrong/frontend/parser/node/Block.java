package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class Block extends TreeNode {
    private Token ltoken = null;
    private Token rtoken = null;
    private ArrayList<BlockItem> blockItemArrayList = new ArrayList<>();
    public Block(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setLtoken(Token ltoken) {
        this.ltoken = ltoken;
    }

    public void setRtoken(Token rtoken) {
        this.rtoken = rtoken;
    }

    public void setBlockItemArrayList(BlockItem blockItem) {
        this.blockItemArrayList.add(blockItem);
    }
}
