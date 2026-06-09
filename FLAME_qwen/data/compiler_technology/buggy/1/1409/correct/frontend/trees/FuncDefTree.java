package frontend.trees;

import java.io.PrintStream;

public class FuncDefTree extends Tree {
    public FuncTypeTree funcType;
    public String ident;
    public FuncFParamsTree params;
    public BlockTree block;
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        funcType.walk(printStream);
        printStream.println("IDENFR "+ident);
        printStream.println("LPARENT (");

        if (params != null) {
            params.walk(printStream);
        }

        printStream.println("RPARENT )");

        block.walk(printStream);

        printStream.println("<FuncDef>");

    }

    @Override
    public String getType() {
        return "FuncDef";
    }
}
