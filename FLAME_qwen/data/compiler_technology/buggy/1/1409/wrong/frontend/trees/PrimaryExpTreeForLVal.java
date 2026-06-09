package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class PrimaryExpTreeForLVal extends PrimaryExpTree {
    public LValTree lVal;

    @Override
    public void walk(PrintStream printStream) {
        lVal.walk(printStream);

        printStream.println("<PrimaryExp>");
    }
}
