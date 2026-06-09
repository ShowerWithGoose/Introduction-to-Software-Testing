package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class BTypeTree extends Tree {
    //public LexType type = LexType.INTTK;
    public LexType type;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println(type+" "+type.get_LexType_s_value());
    }

    @Override
    public String getType() {
        return "BType";
    }
}
