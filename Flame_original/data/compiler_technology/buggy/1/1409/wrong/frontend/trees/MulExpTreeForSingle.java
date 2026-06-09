package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class MulExpTreeForSingle extends MulExpTree {
    public UnaryExpTree unaryExp;

    @Override
    public void walk(PrintStream printStream) {
        unaryExp.walk(printStream);

        printStream.println("<MulExp>");
    }
}
