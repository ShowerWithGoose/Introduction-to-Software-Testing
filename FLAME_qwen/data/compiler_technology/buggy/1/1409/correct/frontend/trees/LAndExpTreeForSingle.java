package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class LAndExpTreeForSingle extends LAndExpTree {
    public EqExpTree eqExp;

    @Override
    public void walk(PrintStream printStream) {
        eqExp.walk(printStream);

        printStream.println("<LAndExp>");
    }
}
