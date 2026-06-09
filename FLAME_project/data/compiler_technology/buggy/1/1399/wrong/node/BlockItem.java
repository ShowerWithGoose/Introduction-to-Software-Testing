/********************************************************************************
 * @FileName     : BlockItem.java
 * @Author       :
 * @Description  : 语句块项
 * @Notice       : BlockItem -> Decl | Stmt
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

public class BlockItem implements ASTNode {
    private Decl decl;
    private Stmt stmt;

    public BlockItem(Decl decl, Stmt stmt) {
        this.decl = decl;
        this.stmt = stmt;
    }


    @Override
    public void printInfo() {
        if (decl != null) {
            decl.printInfo();
        }
        else {
            stmt.printInfo();
        }
    }

    public void setDecl(Decl decl) {
        this.decl = decl;
    }

    public void setStmt(Stmt stmt) {
        this.stmt = stmt;
    }

    public Decl getDecl() {
        return decl;
    }

    public Stmt getStmt() {
        return stmt;
    }
}
