package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class FuncTypeTree extends Tree {
    public LexType type;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println(type+" "+type.get_LexType_s_value());
        printStream.println("<FuncType>");
    }

    @Override
    public String getType() {
        return "FuncType";
    }
}
