package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForLoop extends StmtTree {
    public ForStmtTree forStmt1;
    public CondTree cond;
    public ForStmtTree forStmt2;
    public StmtTree stmt;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("FORTK for");
        printStream.println("LPARENT (");

        if (forStmt1 != null) {
            forStmt1.walk(printStream);
        }

        printStream.println("SEMICN ;");

        if (cond != null) {
            cond.walk(printStream);
        }

        printStream.println("SEMICN ;");

        if (forStmt2 != null) {
            forStmt2.walk(printStream);
        }

        printStream.println("RPARENT )");

        stmt.walk(printStream);

        printStream.println("<Stmt>");
    }
}
