package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;
    private int op;


    public BlockItem(Decl decl) {
        this.decl = decl;
        this.op = 0;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
        this.op = 1;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (this.op == 1) {
            sb.append(this.stmt.print());
        }
        else {
            sb.append(this.decl.print());
        }
        return sb.toString();
    }

    public static BlockItem parse(TokenIterator iterator) {
        Token token = iterator.next();
        if (token.getType().equals(Token.Type.CONSTTK) ||
                token.getType().equals(Token.Type.INTTK) || token.getType().equals(Token.Type.CHARTK)) {
            iterator.back();
            Decl decl = Decl.parse(iterator);
            return new BlockItem(decl);
        }
        else {
            iterator.back();
            Stmt stmt = Stmt.parse(iterator);
            return new BlockItem(stmt);

        }
    }
}
