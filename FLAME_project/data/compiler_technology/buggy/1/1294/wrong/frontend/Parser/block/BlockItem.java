package frontend.Parser.block;

import frontend.Parser.GrammarNode;
import frontend.Parser.declaration.Decl;
import frontend.Parser.statement.Stmt;

public class BlockItem implements GrammarNode {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
        this.stmt = null;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
        this.decl = null;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        if (stmt == null) {
            sb.append(decl.grammarOutput());
        } else {
            sb.append(stmt.grammarOutput());
        }
        return sb.toString();
    }
}
