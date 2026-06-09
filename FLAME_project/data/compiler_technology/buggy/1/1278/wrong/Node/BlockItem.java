package Node;
import Tools.Token;
import Tools.WriteFile;

public class BlockItem extends Node {
    Decl decl = null;
    Stmt stmt = null;

    public BlockItem(int lineno, Node node) {
        super(lineno);
        if (node instanceof Decl) {
            this.decl = (Decl) node;
        } else if (node instanceof Stmt) {
            this.stmt = (Stmt) node;
        } else {
            WriteFile.MakeFile("BlockItem ERROR\n");
        }
    }

    public void checkOut() {
        if (decl != null) {
            decl.checkOut();
        } else {
            stmt.checkOut();
        }
        //Tools.WriteFile.MakeFile("<BlockItem>");
    }
}
