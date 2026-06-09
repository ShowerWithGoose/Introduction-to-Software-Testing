package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class NumberTree extends Tree {
    public String intConst;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("INTCON "+intConst);

        printStream.println("<Number>");
    }

    @Override
    public String getType() {
        return "Number";
    }
}
