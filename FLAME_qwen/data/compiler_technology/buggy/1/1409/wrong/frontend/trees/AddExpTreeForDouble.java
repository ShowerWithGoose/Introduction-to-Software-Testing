package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class AddExpTreeForDouble extends AddExpTree {
    public AddExpTree addExp;
    public LexType op;
    public MulExpTree mulExp;

    @Override
    public void walk(PrintStream printStream) {
        addExp.walk(printStream);
        printStream.println(op+" "+op.get_LexType_s_value());
        mulExp.walk(printStream);
        printStream.println("<AddExp>");
    }
}
