package node;

import frontend.Parser;

public class BlockItem {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.BlockItem;
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl) {
        this.decl = decl;
    }

    public BlockItem(Stmt stmt) {
        this.stmt = stmt;
    }

    public boolean isDecl() {
        return decl != null;
    }

    public boolean isStmt() {
        return stmt != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (isDecl()) {
            ret.append("\n").append(decl);
        } else {
            ret.append("\n").append(stmt);
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
