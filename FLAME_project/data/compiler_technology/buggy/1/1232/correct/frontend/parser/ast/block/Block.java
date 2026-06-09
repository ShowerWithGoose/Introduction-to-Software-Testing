package frontend.parser.ast.block;

import frontend.lexer.Token;

import java.util.ArrayList;

public class Block {
    private String type = "<Block>";
    private Token lBrace;
    private ArrayList<BlockItem> BlockItems;
    private Token rBrace;

    public Block(Token lBrace, ArrayList<BlockItem> BlockItems, Token rBrace) {
        this.lBrace = lBrace;
        this.BlockItems = BlockItems;
        this.rBrace = rBrace;
    }

    public Block(Token lBrace, Token rBrace) {
        this.lBrace = lBrace;
        this.BlockItems = null;
        this.rBrace = rBrace;
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(lBrace.getOutput());
        for (BlockItem i : BlockItems) {
            out.append(i.getOutput());
        }
        out.append(rBrace.getOutput());
        out.append(type + "\n");
        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        for (BlockItem i : BlockItems) {
            String tmp = i.getError();
            if (tmp != null) {
                //System.err.println("Block Error: " + tmp);

                out.append(i.getError());
            }
        }
        return out.toString();
    }
    
}
