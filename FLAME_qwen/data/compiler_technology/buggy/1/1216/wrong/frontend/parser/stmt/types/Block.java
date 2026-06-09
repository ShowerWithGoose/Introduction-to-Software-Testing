package frontend.parser.stmt.types;

import frontend.lexer.Token;

import java.util.ArrayList;

//Block â†’ '{' { BlockItem } '}'
public class Block {
    private final ArrayList<BlockItem> blockItems;
    private final Token lBrace, rBrace;
    public Block(Token lBrace, ArrayList<BlockItem> blockItems, Token rBrace) {
        this.lBrace = lBrace;
        this.blockItems = blockItems;
        this.rBrace = rBrace;
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(lBrace);
        for (BlockItem blockItem: blockItems) {
            res.append(blockItem);
        }
        res.append(rBrace);
        res.append("<Block>\n");
        return res.toString();
    }

    public Token getRBrace() {
        return this.rBrace;
    }
    public ArrayList<BlockItem> getBlockItems() {
        return this.blockItems;
    }

    public Token getLBrace() {
        return this.lBrace;
    }
}
