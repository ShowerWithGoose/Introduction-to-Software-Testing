package node;

import java.util.ArrayList;

public class StmtNode implements TreeNode {
    private ArrayList<TreeNode> nodes;

    public StmtNode(ArrayList<TreeNode> nodes) {
        this.nodes = nodes;
    }

    public void print() {

        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<Stmt>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }


    public LValNode getLVal() {
        return (LValNode) (nodes.get(0));
    }

    public ExpNode getExp() {
        if (nodes.get(2) instanceof  ExpNode) {
            return (ExpNode) (nodes.get(2));
        }
        return null;
    }

    public StmtNode getStmt1() {
        for (TreeNode treeNode : nodes) {
            if (treeNode instanceof StmtNode) {
                return (StmtNode) treeNode;
            }
        }
        return null;
    }

    public StmtNode getStmt2() {
        int check = 0;
        for (TreeNode treeNode : nodes) {
            if (treeNode instanceof Token) {
                if (((Token) treeNode).getIdent().equals("else")) {
                    check = 1;
                }
            }
            if (treeNode instanceof StmtNode && check == 1) {
                return (StmtNode) treeNode;
            }
        }
        return null;
    }

    public ForStmtNode getForStmt1() {
        int check = 0;
        for (TreeNode treeNode:nodes) {
            if (treeNode instanceof Token) {
                if (((Token) treeNode).getIdent().equals(";")) {
                    check = 1;
                }
            }
            if (treeNode instanceof ForStmtNode && check == 0) {
                return (ForStmtNode) treeNode;
            }
        }
        return null;
    }

    public ForStmtNode getForStmt2() {
        int check = 0;
        for (TreeNode treeNode:nodes) {
            if (treeNode instanceof Token) {
                if (((Token) treeNode).getIdent().equals(";")) {
                    check++;
                }
            }
            if (treeNode instanceof ForStmtNode && check == 2) {
                return (ForStmtNode) treeNode;
            }
        }
        return null;
    }

    public CondNode getCond() {
        for (TreeNode treeNode:nodes) {

            if (treeNode instanceof CondNode) {
                return (CondNode) treeNode;
            }
        }
        return null;
    }
}
