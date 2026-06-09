package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class RelExpTreeForDouble extends RelExpTree {
    public RelExpTree relExp;
    public LexType op;
    public AddExpTree addExp;

    @Override
    public void walk(PrintStream printStream) {
        relExp.walk(printStream);

        printStream.println(op+" "+op.get_LexType_s_value());

        addExp.walk(printStream);

        printStream.println("<RelExp>");
    }
}
