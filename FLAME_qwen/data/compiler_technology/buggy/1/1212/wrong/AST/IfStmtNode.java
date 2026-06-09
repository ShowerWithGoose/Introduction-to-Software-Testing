package AST;
import IO.*;

import java.io.IOException;

public class IfStmtNode extends ASTNode {

    ASTNodes type = ASTNodes.IfStmt;
    CondNode condNode;

    StmtNode ifStmt;
    public IfStmtNode(CondNode cond, StmtNode ifStmt) {
        this.condNode = cond;
        this.ifStmt = ifStmt;
    }

    public StmtNode getIfStmt() {
        return ifStmt;
    }

    public ASTNodes getType() {
        return type;
    }

    public CondNode getCondNode() {
        return condNode;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("IFTK if\n");
        io.getParserWriter().write("LPARENT (\n");
        condNode.postOrderTraversal(io);
        io.getParserWriter().write("RPARENT )\n");
        ifStmt.postOrderTraversal(io);
    }

    
    public void postOrderNoPrint() {

        condNode.postOrderNoPrint();

        ifStmt.postOrderNoPrint();
    }
}
