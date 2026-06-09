package AST;
import IO.*;

import java.io.IOException;

public class IfElseStmtNode extends ASTNode{

    ASTNodes type = ASTNodes.IfElse;
    CondNode cond;
    StmtNode ifStmt;
    StmtNode elseStmt;

    public IfElseStmtNode(CondNode cond, StmtNode ifStmt, StmtNode elseStmt) {
        this.cond = cond;
        this.ifStmt = ifStmt;
        this.elseStmt = elseStmt;
    }

    public ASTNodes getType() {
        return type;
    }

    public StmtNode getElseStmt() {
        return elseStmt;
    }

    public StmtNode getIfStmt() {
        return ifStmt;
    }

    public CondNode getCond() {
        return cond;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        io.getParserWriter().write("IFTK if\n");
        io.getParserWriter().write("LPARENT (\n");
        cond.postOrderTraversal(io);
        io.getParserWriter().write("RPARENT )\n");
        ifStmt.postOrderTraversal(io);
        io.getParserWriter().write("ELSETK else\n");
        elseStmt.postOrderTraversal(io);
    }

    
    public void postOrderNoPrint() {

        cond.postOrderNoPrint();

        ifStmt.postOrderNoPrint();

        elseStmt.postOrderNoPrint();
    }
}
