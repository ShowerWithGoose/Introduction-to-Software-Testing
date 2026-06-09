package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class Block {
    private Token left;
    private ArrayList<BlockItem> blockItems;
    private Token right;

    public Block(Token left, ArrayList<BlockItem> blockItems, Token right) {
        this.left = left;
        this.blockItems = blockItems;
        this.right = right;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(left.print());
        for (int i = 0; i < blockItems.size(); i++) {
            sb.append(blockItems.get(i).print());
        }
        sb.append(right.print());
        sb.append("<Block>\n");
        return sb.toString();
    }

    public static Block parse(TokenIterator iterator) {
        Token left = iterator.next();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        Token token = iterator.next();
        while (!token.getType().equals(Token.Type.RBRACE)) {
            iterator.back();
            BlockItem blockItem = BlockItem.parse(iterator);
            blockItems.add(blockItem);
            token = iterator.next();
        }
        Token right = token;
        return new Block(left,blockItems,right);
    }
}
