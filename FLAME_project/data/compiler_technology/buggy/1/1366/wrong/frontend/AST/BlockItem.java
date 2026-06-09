package frontend.AST;

import frontend.AST.Decl.Decl;

public class BlockItem {
    private int type;
    //type = 1
    private Decl decl = null;
    //type = 2
    private Stmt stmt = null;

    public BlockItem(Decl d) {
        type = 1;
        this.decl = d;
    }

    public BlockItem(Stmt s) {
        type = 2;
        this.stmt = s;
    }

    public void postorder() {
        if (type == 1) {
            decl.postorder();
        } else {
            stmt.postorder();
        }
    }
    //BlockItem â†’ Decl | Stmt
}
