package frontend.GrammaticalElements.statement;

import frontend.Token;

import java.util.ArrayList;

public class Block {
    /*const string name = "<Block>";
    Token leftBrace; // {
    vector<BlockItem> blockItems;
    Token rightBrace; // }*/
    private final String name = "<Block>";
    private Token leftBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rightBrace;

    public Block(Token leftBrace, ArrayList<BlockItem> blockItems, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItems = blockItems;
        this.rightBrace = rightBrace;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.toString());
        for (BlockItem blockItem : blockItems) {
            sb.append(blockItem.toString());
        }
        sb.append(rightBrace.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
