package Parser.Stmt;

import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class Stmt implements TreeNode {
    private final String name = "<Stmt>";
    private StmtEle stmtEle;

    public Stmt(StmtEle stmtEle) {
        this.stmtEle = stmtEle;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtEle.print_tree());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}