package AST;
import IO.*;

import java.io.IOException;

public class ForNode extends ASTNode{

    ASTNodes type = ASTNodes.ForNode;
    ForStmt forStmt;
    CondNode condNode;
    ForStmt forStmt2;
    StmtNode s;

    public ForNode(ForStmt forStmt, CondNode condNode, ForStmt forStmt2, StmtNode s) {
        this.forStmt = forStmt;
        this.condNode = condNode;
        this.forStmt2 = forStmt2;
        this.s = s;
    }

    public ForStmt getForStmt() {
        return forStmt;
    }

    public CondNode getCondNode() {
        return condNode;
    }

    public ForStmt getForStmt2() {
        return forStmt2;
    }

    public StmtNode getS() {
        return s;
    }

    public ASTNodes getType() {
        return type;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("FORTK for\n");
        io.getParserWriter().write("LPARENT (\n");
        if (forStmt != null) forStmt.postOrderTraversal(io);
        io.getParserWriter().write("SEMICN ;\n");
        if (condNode != null) condNode.postOrderTraversal(io);
        io.getParserWriter().write("SEMICN ;\n");
        if (forStmt2 != null) forStmt2.postOrderTraversal(io);
        io.getParserWriter().write("RPARENT )\n");
        if (s!= null) s.postOrderTraversal(io);
    }

    
    public void postOrderNoPrint() {
        if (forStmt != null) forStmt.postOrderNoPrint();

        if (condNode != null) condNode.postOrderNoPrint();

        if (forStmt2 != null) forStmt2.postOrderNoPrint();

        if (s!= null) s.postOrderNoPrint();
    }
}
