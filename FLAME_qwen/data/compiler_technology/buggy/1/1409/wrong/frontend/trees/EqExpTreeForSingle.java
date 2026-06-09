package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class EqExpTreeForSingle extends EqExpTree {
    public RelExpTree relExp;

    @Override
    public void walk(PrintStream printStream) {
        relExp.walk(printStream);
        printStream.println("<EqExp>");
    }
}
