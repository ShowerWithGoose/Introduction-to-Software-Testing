package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block {
    public String LBRACE;
    public ArrayList<BlockItem> blockItems = new ArrayList<>();
    public String RBRACE;

    public void print(FileWriter lw) throws IOException {
        lw.write("LBRACE " + LBRACE + "\n");
        for(BlockItem blockItem : blockItems) {
            blockItem.print(lw);
        }
        lw.write("RBRACE " + RBRACE + "\n");
        lw.write("<Block>\n");
    }
}
