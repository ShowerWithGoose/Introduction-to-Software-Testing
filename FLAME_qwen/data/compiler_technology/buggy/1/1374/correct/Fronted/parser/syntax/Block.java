package Fronted.parser.syntax;

import Fronted.lexer.Token;
import java.util.ArrayList;

// Block â†’ '{' { BlockItem } '}'
public class Block {

    private static final String name = "<Block>";

    private Token lbrace = null;

    private ArrayList<BlockItem> blockItemList = null;

    private Token rbrace = null;

    public Block(Token lbrace, ArrayList<BlockItem> blockItemList, Token rbrace) {
        this.lbrace = lbrace;
        this.blockItemList = blockItemList;
        this.rbrace = rbrace;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(lbrace);
        for (BlockItem blockItem : blockItemList) {
            out.append(blockItem);
        }
        out.append(rbrace);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getLbrace() {
        return lbrace;
    }

    public ArrayList<BlockItem> getBlockItemList() {
        return blockItemList;
    }

    public Token getRbrace() {
        return rbrace;
    }

    public void setLbrace(Token lbrace) {
        this.lbrace = lbrace;
    }

    public void setBlockItemList(ArrayList<BlockItem> blockItemList) {
        this.blockItemList = blockItemList;
    }

    public void setRbrace(Token rbrace) {
        this.rbrace = rbrace;
    }
}
