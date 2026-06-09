package struct;

import token.Token;

import java.util.List;

/* Block â†’ '{' { BlockItem } '}' */
public class Block {
    private final Token lBraceToken;
    private final List<BlockItem> blockItem;
    private final Token rBraceToken;

    public Block(Token lBraceToken, List<BlockItem> blockItem, Token rBraceToken) {
        this.lBraceToken = lBraceToken;
        this.blockItem = blockItem;
        this.rBraceToken = rBraceToken;
    }

    public Token getLBraceToken() {
        return lBraceToken;
    }

    public List<BlockItem> getBlockItem() {
        return blockItem;
    }

    public Token getRBraceToken() {
        return rBraceToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lBraceToken.toString());
        for (BlockItem item : blockItem) {
            sb.append(item.toString());
        }
        sb.append(rBraceToken.toString());
        sb.append("<Block>\n");
        return sb.toString();
    }
}
