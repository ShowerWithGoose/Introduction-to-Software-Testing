package syntacticanalysis.node;

import lexicalanalysis.Token;

import java.util.ArrayList;

public class Block {
    private final String name = "<Block>";
    private final Token lbrace;
    private final ArrayList<BlockItem> blockItems;
    private final Token rbrace;

    public Block(Token lbrace, ArrayList<BlockItem> blockItems, Token rbrace)
    {
        this.lbrace = lbrace;
        this.blockItems = blockItems;
        this.rbrace = rbrace;
    }

    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        sb.append("\n");
        if (blockItems != null) {
            for (BlockItem blockItem : blockItems) {
                sb.append(blockItem.syntaxOutput());
                sb.append("\n");
            }
        }
        sb.append(rbrace);
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
