package frontend.trees;

import frontend.Parser;


import java.io.PrintStream;
import java.util.function.Consumer;

public class AddExpTreeForSingle extends AddExpTree {
    public MulExpTree mulExp;

    @Override
    public void walk(PrintStream printStream) {
        mulExp.walk(printStream);
        printStream.println("<AddExp>");
    }
}
