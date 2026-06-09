package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class RelExpTreeForSingle extends RelExpTree {
    public AddExpTree addExp;

    @Override
    public void walk(PrintStream printStream) {
        addExp.walk(printStream);

        printStream.println("<RelExp>");
    }
}
