package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;
import frontend.parser.func.Block;

import java.util.HashSet;

public class BlockStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Block.FIRST);
    }

    private Block block;

    public BlockStmt(Block block) {
        this.block = block;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.block.toString();
        string += "<Stmt>\n";
        return string;
    }
}
