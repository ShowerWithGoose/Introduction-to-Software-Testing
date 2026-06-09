package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class UnaryExpTreeForFuncCall extends UnaryExpTree {
    public String ident;
    public FuncRParamsTree params;
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("IDENFR "+ident);
        printStream.println("LPARENT (");

        if (params != null) {
            params.walk(printStream);
        }

        printStream.println("RPARENT )");

        printStream.println("<UnaryExp>");
    }
}
