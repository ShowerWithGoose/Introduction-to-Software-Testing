package frontend.Parser.block;

import frontend.Lexer.Token;
import frontend.Parser.statement.StmtPort;

import java.util.ArrayList;

public class Block implements StmtPort {
    private final String grammarName = "<Block>";
    private Token lBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rBrace;

    public Block(Token lBrace, ArrayList<BlockItem> blockItems, Token rBrace) {
        this.lBrace = lBrace;
        this.blockItems = blockItems;
        this.rBrace = rBrace;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lBrace.grammarOutput());
        if (this.blockItems != null && !this.blockItems.isEmpty()) {
            for (BlockItem blockItem : this.blockItems) {
                sb.append(blockItem.grammarOutput());
            }
        }
        sb.append(this.rBrace.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
