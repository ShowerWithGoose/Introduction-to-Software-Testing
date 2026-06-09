package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForIfElse extends StmtTree {
    public CondTree cond;
    public StmtTree ifStmt;
    public StmtTree elseStmt;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("IFTK if");
        printStream.println("LPARENT (");

        cond.walk(printStream);

        printStream.println("RPARENT )");

        ifStmt.walk(printStream);

        if (elseStmt != null) {
            printStream.println("ELSETK else");
            elseStmt.walk(printStream);
        }

        printStream.println("<Stmt>");
    }
}
