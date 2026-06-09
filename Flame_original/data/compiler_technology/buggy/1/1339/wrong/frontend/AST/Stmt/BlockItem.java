package frontend.AST.Stmt;

import frontend.AST.Decl.Decl;
import frontend.AST.SyntaxNode;
//BlockItem → Decl | Stmt
public class BlockItem implements SyntaxNode {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    @Override
    public void print() {
        if (decl != null) {
            decl.print();
        } else {
            stmt.print();
        }

    }

    @Override
    public String getName() {
        // 不需要打印
        return "<BlockItem>";
    }
}
