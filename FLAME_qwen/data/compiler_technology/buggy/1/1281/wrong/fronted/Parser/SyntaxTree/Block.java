package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 10:52
 */
public class Block implements SyntaxNode{
    private final String name = "<Block>";
    private Token leftBrace; // '{'
    private ArrayList<BlockItem> blockItems = null;  //may empty
    private Token rightBrace; // '}'

    public Block(Token leftBrace, ArrayList<BlockItem> blockItems, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItems = blockItems;
        this.rightBrace = rightBrace;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.output());
        if (!this.blockItems.isEmpty() ) {
            for(BlockItem blockItem : this.blockItems){
                sb.append(blockItem.output());
            }
        }
        sb.append(this.rightBrace.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
