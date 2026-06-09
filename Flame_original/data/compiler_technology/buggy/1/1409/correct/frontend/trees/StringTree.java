package frontend.trees;

import frontend.LexType;

import java.io.PrintStream;
import java.util.function.Consumer;

public class StringTree extends Tree {
    public String strConst;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("STRCON "+strConst);

    }

    @Override
    public String getType() {
        return "String";
    }
}
