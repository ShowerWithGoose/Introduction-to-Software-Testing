package frontend.trees;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class FuncFParamsTree extends Tree {
    public List<FuncFParamTree> params = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        boolean first = true;

        for (var param : params) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            param.walk(printStream);
        }

        printStream.println("<FuncFParams>");
    }

    @Override
    public String getType() {
        return "FuncFParams";
    }
}
