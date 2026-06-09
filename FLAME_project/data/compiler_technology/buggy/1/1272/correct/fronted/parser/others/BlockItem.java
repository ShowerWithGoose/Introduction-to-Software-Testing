package fronted.parser.others;

import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.declaration.Decl;
import fronted.parser.statement.Stmt;

public class BlockItem {
    //BlockItem â†’ Decl | Stmt

    private Decl decl;

    private Stmt stmt;

    private int type;

    public BlockItem(Decl decl) {
        this.decl = decl;
        this.stmt = null;
        type = 1;
    }

    public BlockItem(Stmt stmt) {
        this.decl = null;
        this.stmt = stmt;
        type = 2;
    }

    @Override
    public String toString() {
        if (type == 1) {
            return decl.toString();
        } else {
            return stmt.toString();
        }
    }

    public static BlockItem parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.CONSTTK)
                ||list.now().getType().equals(TokenType.Type.INTTK)
                ||list.now().getType().equals(TokenType.Type.CHARTK) ) {
            //System.out.println("BlockItem : Decl  " + list.now() + list.getAheadOne(1) + list.getAheadOne(2));
            return new BlockItem(Decl.parse(list));
        } else {
            //System.out.println("BlockItem : Stmt  " + list.now());
            return new BlockItem(Stmt.parse(list));
        }
    }
}
