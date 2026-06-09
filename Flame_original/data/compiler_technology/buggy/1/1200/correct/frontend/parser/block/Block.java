package frontend.parser.block;

import frontend.lexer.Token;

import java.util.ArrayList;

public class Block {
    private final String name = "<Block>";
    private Token lBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rBrace;

    public Block(Token lBrace, ArrayList<BlockItem> blockItems, Token rBrace) {
        this.lBrace = lBrace;
        this.blockItems = blockItems;
        this.rBrace = rBrace;
    }

    public Block(Token lBrace, Token rBrace) {
        this.lBrace = lBrace;
        this.rBrace = rBrace;
        this.blockItems = null;
    }

    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(lBrace.getOutPut());
        for (BlockItem item : blockItems) {
            sb.append(item.getOutPut());
        }
        sb.append(rBrace.getOutPut());
        sb.append(name + "\n");
        return sb.toString();
    }

    public String getError() {
        StringBuilder sb = new StringBuilder();
        for (BlockItem item : blockItems) {
            sb.append(item.getError());
        }
        return sb.toString();
    }
}
