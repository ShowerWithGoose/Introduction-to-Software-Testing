package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class LValTree extends Tree {
    public String ident;
    public List<ExpTree> dimensions = new ArrayList<>();
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("IDENFR "+ident);

        for (var dim : dimensions) {
            printStream.println("LBRACK [");

            dim.walk(printStream);

            printStream.println("RBRACK ]");
        }

        printStream.println("<LVal>");
    }

    @Override
    public String getType() {
        return "LVal";
    }
}
