package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForBlock extends StmtTree {
    public BlockTree block;

    @Override
    public void walk(PrintStream printStream) {
        block.walk(printStream);

        printStream.println("<Stmt>");
    }
}
