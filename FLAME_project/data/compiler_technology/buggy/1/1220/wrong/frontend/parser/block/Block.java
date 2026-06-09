package frontend.parser.block;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.statement.StmtUnit;

import java.util.ArrayList;

public class Block implements StmtUnit, SyntaxUnit {
    // Block → '{' { BlockItem } '}'
    // brace
    private final String name = "<Block>";
    private Token leftBrace;
    private Token rightBrace;
    private ArrayList<BlockItem> blockItems;

    public Block(Token leftBrace, ArrayList<BlockItem> blockItems,
                 Token rightBrace) {
        this.leftBrace = leftBrace;
        this.blockItems = blockItems;
        this.rightBrace = rightBrace;
    }

    @Override
    public String syntaxPrint() {
        //// Block → '{' { BlockItem } '}'
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.syntaxPrint());
        if (blockItems != null && !blockItems.isEmpty()) {
            for (BlockItem b : blockItems) {
                sb.append(b.syntaxPrint());
            }
        }
        sb.append(rightBrace.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
