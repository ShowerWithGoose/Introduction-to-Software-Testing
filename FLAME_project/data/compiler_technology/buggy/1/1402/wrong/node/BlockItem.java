package node;

import java.io.IOException;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl, Stmt stmt) {
        this.decl = decl;
        this.stmt = stmt;
    }

    public void print() throws IOException {
        if(decl!=null)
            decl.print();
        else
            stmt.print();
    }
}
