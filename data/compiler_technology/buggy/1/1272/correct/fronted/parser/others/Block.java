package fronted.parser.others;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class Block {
    //Block â†’ '{' { BlockItem } '}'

    private static final Token leftBrace = new Token(TokenType.Type.LBRACE,"{",1);

    private static final Token rightBrace = new Token(TokenType.Type.RBRACE,"}",1);

    private static final String name = "<Block>\n";

    private ArrayList<BlockItem> items;

    public Block(ArrayList<BlockItem> items) {
        this.items = items;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace);
        for (BlockItem item : items) {
            sb.append(item.toString());
        }
        sb.append(rightBrace);
        sb.append(name);
        return sb.toString();
    }

    public static Block parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.LBRACE)) {
            list.next();
            ArrayList<BlockItem> items = new ArrayList<>();
            if (list.now().getType().equals(TokenType.Type.RBRACE)) {
                list.next();
            } else {
                while (!list.now().getType().equals(TokenType.Type.RBRACE)) {
                    items.add(BlockItem.parse(list));
                }
                list.next();
            }
            return new Block(items);
        } else {
            System.err.println("Error:Block cannot find {");
            return null;
        }
    }
}
