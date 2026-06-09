package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class LAndExpTreeForDouble extends LAndExpTree {
    public LAndExpTree lAndExp;
    public EqExpTree eqExp;

    @Override
    public void walk(PrintStream printStream) {
        lAndExp.walk(printStream);

        printStream.println("AND &&");

        eqExp.walk(printStream);

        printStream.println("<LAndExp>");
    }
}
