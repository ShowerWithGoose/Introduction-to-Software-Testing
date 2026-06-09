package frontend.nonTerminal.Stmt;

import frontend.nonTerminal.Exp;
import frontend.nonTerminal.Stmt.Stmt;
import frontend.token.token;
import frontend.tool.myWriter;

public class ReturnStmt extends Stmt {
    public token returnToken;
    public Exp returnExp;

    public token semicn;

    @Override
    public void visit() {
        returnToken.visit();
        if (returnExp != null) returnExp.visit();
        if (semicn != null) semicn.visit();
        myWriter.writeNonTerminal("Stmt");
    }
}
