package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class InitValTreeForArray extends InitValTree {
    public List<ExpTree> expTrees = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("LBRACE {");

        boolean first = true;
        for (var exp : expTrees) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            exp.walk(printStream);
        }

        printStream.println("RBRACE }");
        printStream.println("<InitVal>");

    }
}
