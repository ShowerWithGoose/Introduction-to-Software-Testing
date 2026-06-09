package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public abstract class Tree {
    public abstract void walk(PrintStream printStream);
    public abstract String getType();
}
