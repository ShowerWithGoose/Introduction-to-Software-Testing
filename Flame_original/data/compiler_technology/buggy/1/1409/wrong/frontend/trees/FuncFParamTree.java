package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.List;
import java.util.function.Consumer;

public class FuncFParamTree extends Tree {
    public BTypeTree type;
    public String ident;
    public List<ConstExpTree> dimensions;
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        type.walk(printStream);

        printStream.println("IDENFR "+ident);

        if (dimensions != null) {
            printStream.println("LBRACK [");
            printStream.println("RBRACK ]");
            for (var dim : dimensions) {
                printStream.println("LBRACK [");
                dim.walk(printStream);
                printStream.println("RBRACK ]");
            }
        }

        printStream.println("<FuncFParam>");
    }

    @Override
    public String getType() {
        return "FuncFParam";
    }
}
