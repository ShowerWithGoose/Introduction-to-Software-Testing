package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForExp extends StmtTree {
    public ExpTree exp;

    @Override
    public void walk(PrintStream printStream) {
        if (exp != null) {
            exp.walk(printStream);
        }

        printStream.println("SEMICN ;");

        printStream.println("<Stmt>");
    }
}
