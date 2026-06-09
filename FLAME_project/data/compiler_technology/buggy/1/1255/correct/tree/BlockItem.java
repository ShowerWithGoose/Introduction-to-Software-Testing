package tree;

import java.io.FileWriter;
import java.io.IOException;

public class BlockItem {
    private Decl decl;
    private Stmt stmt;

    public void setDecl(Decl decl) {
        this.decl = decl;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (decl != null)
            decl.output(fileWriter);
        else
            stmt.output(fileWriter);
    }
}
