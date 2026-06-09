package frontend.trees;



import java.io.PrintStream;
import java.util.function.Consumer;

public class BlockItemTreeForStmt extends BlockItemTree {
    public StmtTree stmt;

    @Override
    public void walk(PrintStream printStream) {
        stmt.walk(printStream);
    }
}
