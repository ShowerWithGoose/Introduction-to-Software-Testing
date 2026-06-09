package frontend.nonTerminal.Stmt;

import frontend.nonTerminal.Stmt.Stmt;
import frontend.token.token;
import frontend.tool.myWriter;

public class BreakStmt extends Stmt {
    public token breakToken;
    public token semicn;

    @Override
    public void visit() {
        breakToken.visit();
        if (semicn != null) semicn.visit();
        myWriter.writeNonTerminal("Stmt");
    }
}
