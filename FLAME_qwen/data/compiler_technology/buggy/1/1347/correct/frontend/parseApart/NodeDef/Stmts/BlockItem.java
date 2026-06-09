package frontend.parseApart.NodeDef.Stmts;

import frontend.parseApart.NodeDef.Normal.Decl;
import frontend.parseApart.NodeDef.Normal.Stmt;

public class BlockItem {
    private int type;
    private Decl decl;
    private Stmt stmt;

    public BlockItem() {

    }

    public void setDecl(Decl decl) {
        this.type = 1;
        this.decl = decl;
    }

    public void setStmt(Stmt stmt) {
        this.type = 2;
        this.stmt = stmt;
    }

    public String returnSymbolType() {
        String string = "<BlockItem>";
        return string;
    }
}
