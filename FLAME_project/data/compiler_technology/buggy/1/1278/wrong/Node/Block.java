package Node;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;
public class Block extends Node {
    Token l_token;
    Token r_token;
    ArrayList<BlockItem> blockItems;

    public Block(int lineno, Token l_token, ArrayList<BlockItem> blockItems, Token r_token) {
        super(lineno);
        this.l_token = l_token;
        this.blockItems = blockItems;
        this.r_token = r_token;
    }

    public void checkOut() {
        WriteFile.MakeFile(l_token.toString() + "\n");
        for (BlockItem blockItem : blockItems) {
            blockItem.checkOut();
        }
        WriteFile.MakeFile(r_token.toString() + "\n");
        WriteFile.MakeFile("<Block>\n");
    }
}
