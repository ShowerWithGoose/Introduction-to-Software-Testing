package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block {
    private Token leftB;
    private ArrayList<BlockItem> blockItems = new ArrayList<>();
    private Token rightB;

    public void addBlockItem(BlockItem blockItem) {
        blockItems.add(blockItem);
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(leftB.toString() + "\n");
        for (BlockItem blockItem : blockItems) {
            blockItem.output(fileWriter);
        }
        fileWriter.write(rightB.toString() + "\n");
        fileWriter.write("<Block>\n");
    }
}
