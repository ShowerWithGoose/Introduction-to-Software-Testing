package frontend.trees;



import java.io.PrintStream;
import java.util.function.Consumer;

public class BlockItemTreeForDecl extends BlockItemTree {
    public DeclTree decl;

    @Override
    public void walk(PrintStream printStream) {
        decl.walk(printStream);
    }
}
