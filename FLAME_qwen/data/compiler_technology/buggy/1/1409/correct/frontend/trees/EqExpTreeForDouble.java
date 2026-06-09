package frontend.trees;
import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class EqExpTreeForDouble extends EqExpTree {
    public EqExpTree eqExp;
    public LexType op;
    public RelExpTree relExp;

    @Override
    public void walk(PrintStream printStream) {
        eqExp.walk(printStream);
        printStream.println(op+" "+op.get_LexType_s_value());

        relExp.walk(printStream);

        printStream.println("<EqExp>");
    }
}
