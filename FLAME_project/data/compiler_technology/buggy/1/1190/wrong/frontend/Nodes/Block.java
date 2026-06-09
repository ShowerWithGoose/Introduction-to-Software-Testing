package frontend.Nodes;

import frontend.Token;

import java.util.ArrayList;
import java.util.List;

public class Block implements Node {
    private Token lBrace;
    private List<BlockItem> blockItemList;
    private Token rBrace;

    public Block() {
        this.lBrace = null;
        this.blockItemList = new ArrayList<>();
        this.rBrace = null;
    }

    public void addLBrace(Token lBrace) {
        this.lBrace = lBrace;
    }

    public void addBlockItem(BlockItem blockItem) {
        blockItemList.add(blockItem);
    }

    public void addRBrace(Token rBrace) {
        this.rBrace = rBrace;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (lBrace != null) {
            sb.append(lBrace.error());
        }
        for (BlockItem blockItem : blockItemList) {
            sb.append(blockItem.error());
        }
        if (rBrace != null) {
            sb.append(rBrace.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (lBrace != null) {
            sb.append(lBrace.toString());
        }
        for (BlockItem blockItem : blockItemList) {
            sb.append(blockItem.toString());
        }
        if (rBrace != null) {
            sb.append(rBrace.toString());
        }
        sb.append("<Block>\n");
        return sb.toString();
    }
}
