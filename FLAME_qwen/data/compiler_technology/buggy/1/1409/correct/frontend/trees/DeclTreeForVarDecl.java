package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class DeclTreeForVarDecl extends DeclTree {
    public VarDeclTree varDecl;

    @Override
    public void walk(PrintStream printStream) {
        varDecl.walk(printStream);
    }
}
