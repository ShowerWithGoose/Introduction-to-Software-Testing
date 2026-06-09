package ast;

import enum_package.BlockItemType;

public class BlockItemNode {
    // BlockItem -> Decl | Stmt
    public DeclNode decl; // 声明项（如果有的话）
    public StmtNode stmt; // 语句项（如果有的话）

    public BlockItemNode(DeclNode decl, StmtNode stmt) {
        this.decl = decl;
        this.stmt = stmt;
    }

    public void print() {
        if (decl != null) {
            decl.print();
        } else if (stmt != null) {
            stmt.print();
        }
    }
}
