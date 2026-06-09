package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class UnaryOpTree extends Tree {
    public LexType opType;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println(opType+" "+opType.get_LexType_s_value());

        printStream.println("<UnaryOp>");
    }

    @Override
    public String getType() {
        return "UnaryOp";
    }
}
