package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
Block â†’ '{' { BlockItem } '}'
 */
public class Block implements SyntaxNode {
    private final String name = "<Block>";
    private Token lbrace;
    private ArrayList<BlockItem> blockItems;
    private Token rbrace;

    public Block(Token lbrace, ArrayList<BlockItem> blockItems, Token rbrace) {
        this.lbrace = lbrace;
        this.rbrace = rbrace;
        this.blockItems = blockItems;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        for (BlockItem item : blockItems) {
            sb.append(item);
        }
        sb.append(rbrace);
        sb.append(name + "\n");
        return sb.toString();
    }
}
