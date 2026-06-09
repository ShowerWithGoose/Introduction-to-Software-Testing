package frontend.trees;

import java.io.PrintStream;

public class DeclTreeForConstDecl extends DeclTree {
    public ConstDeclTree constDecl;

    @Override
    public void walk(PrintStream printStream) {
        constDecl.walk(printStream);
    }
}
