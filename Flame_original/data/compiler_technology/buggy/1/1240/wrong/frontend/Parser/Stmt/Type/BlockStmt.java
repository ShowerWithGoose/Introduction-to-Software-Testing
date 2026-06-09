package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class BlockStmt implements StmtInter {
    // Block â†’ '{' { BlockItem } '}'
    // StmtInter -> Block
    private final ArrayList<LexType> braces;
    private final ArrayList<BlockItem> blockItem;

    public BlockStmt(ArrayList<LexType> braces, ArrayList<BlockItem> blockItem) {
        this.braces = braces;
        this.blockItem = blockItem;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(braces.get(0).toString());
        for (BlockItem item : blockItem) {
            sb.append(item.toString());
        }
        sb.append(braces.get(1).toString());
        sb.append("<Block>\n");
        return sb.toString();
    }
}
