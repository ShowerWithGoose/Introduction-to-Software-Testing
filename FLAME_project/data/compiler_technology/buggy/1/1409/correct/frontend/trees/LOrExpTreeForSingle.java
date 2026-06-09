package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class LOrExpTreeForSingle extends LOrExpTree {
    public LAndExpTree lAndExp;

    @Override
    public void walk(PrintStream printStream) {
        lAndExp.walk(printStream);

        printStream.println("<LOrExp>");
    }
}
