package Parser;

import Lexer.Token;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class Block implements TreeNode{
    private final String value = "<Block>";
    private Token leftBrace; // '{'
    private ArrayList<BlockItem> blockItems;
    private Token rightBrace; // '}'

    public Block(Token leftBrace,
                 ArrayList<BlockItem> blockItems,
                 Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItems = blockItems;
        this.rightBrace = rightBrace;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.leftBrace.toStringprint());
        for(int i=0;i<this.blockItems.size();i++){
            sb.append(this.blockItems.get(i).print_tree());
        }
        sb.append(this.rightBrace.toStringprint());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
