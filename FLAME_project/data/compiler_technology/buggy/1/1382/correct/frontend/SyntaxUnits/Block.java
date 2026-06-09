package frontend.SyntaxUnits;

import java.util.ArrayList;

public class Block implements SyntaxUnit{
    private ArrayList<BlockItem>  blockItems;

    public Block(ArrayList<BlockItem> blockItems) {
        this.blockItems = blockItems;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("LBRACE" + " {" +  "\n");
        for (BlockItem blockItem : blockItems) {
            stringBuilder.append(blockItem.toPrint());
        }
        stringBuilder.append("RBRACE" + " }" +  "\n");
        stringBuilder.append("<Block>\n");
        return stringBuilder.toString();
    }
}
