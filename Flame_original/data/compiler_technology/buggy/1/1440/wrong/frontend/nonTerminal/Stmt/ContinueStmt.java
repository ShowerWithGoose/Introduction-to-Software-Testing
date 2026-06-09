package frontend.nonTerminal.Stmt;


import frontend.token.token;
import frontend.tool.myWriter;

public class ContinueStmt extends Stmt {
    public token continueToken;
    public token semicn;

    @Override
    public void visit() {
        continueToken.visit();
        if (semicn != null) semicn.visit();
        myWriter.writeNonTerminal("Stmt");
    }
}
