package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class MulExpTreeForDouble extends MulExpTree {
    public MulExpTree mulExp;
    public LexType op;
    public UnaryExpTree unaryExp;

    @Override
    public void walk(PrintStream printStream) {
        mulExp.walk(printStream);

        printStream.println(op+" "+op.get_LexType_s_value());

        unaryExp.walk(printStream);

        printStream.println("<MulExp>");
    }
}
