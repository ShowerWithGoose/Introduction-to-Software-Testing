package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class BlockItem {
    public Decl decl;
    public Stmt stmt;

    public void print(FileWriter lw) throws IOException {
        if(decl != null)
            decl.print(lw);
        if(stmt != null)
            stmt.print(lw);
    }
}
