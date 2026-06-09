package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class InitValTreeForExp extends InitValTree {
    public ExpTree exp;

    @Override
    public void walk(PrintStream printStream) {
        exp.walk(printStream);

        printStream.println("<InitVal>");
    }
}
