package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class FuncRParamsTree extends Tree {
    public List<ExpTree> exps = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        boolean first = true;

        for (var exp : exps) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            exp.walk(printStream);
        }

        printStream.println("<FuncRParams>");
    }

    @Override
    public String getType() {
        return "FuncRParams";
    }
}
