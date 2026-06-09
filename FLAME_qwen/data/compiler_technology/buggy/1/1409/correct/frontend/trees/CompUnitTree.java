package frontend.trees;

 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class CompUnitTree extends Tree {
    public final List<DeclTree> declares = new ArrayList<>();
    public final List<FuncDefTree> funcs = new ArrayList<>();
    public MainFuncDefTree mainFunc;

    @Override
    public void walk(PrintStream printStream) {
        for (var declare : declares) {
            declare.walk(printStream);
        }

        for (var func : funcs) {
            func.walk(printStream);
        }

        mainFunc.walk(printStream);

        printStream.println("<CompUnit>");

    }

    @Override
    public String getType() {
        return "CompUnit";
    }
}
