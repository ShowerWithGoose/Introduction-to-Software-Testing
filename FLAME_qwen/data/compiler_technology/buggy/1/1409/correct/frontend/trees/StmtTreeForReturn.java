package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForReturn extends StmtTree {
    public ExpTree exp;
    public int returnLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("RETURNTK return");

        if (exp != null) {
            exp.walk(printStream);
        }

        printStream.println("SEMICN ;");

        printStream.println("<Stmt>");
    }
}
