package frontend.Parser.Statement;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class Block implements StmtEle {
    private Token lbraceToken;
    private ArrayList<BlockItem> blockItems;    // 可选
    private Token rbraceToken;

    public Block (Token lbraceToken,
                  ArrayList blockItems,
                  Token rbraceToken) {
        this.lbraceToken = lbraceToken;
        this.blockItems = blockItems;
        this.rbraceToken = rbraceToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbraceToken);
        if (!blockItems.isEmpty()) {
            for (BlockItem blockItem : blockItems) {
                sb.append(blockItem.printString());
            }
        }
        sb.append(rbraceToken);
        sb.append("<" + "Block" + ">\n");
        return sb.toString();
    }
}
