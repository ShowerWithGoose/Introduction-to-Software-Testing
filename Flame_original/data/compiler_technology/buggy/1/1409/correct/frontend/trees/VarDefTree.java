package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class VarDefTree extends Tree {
    public String ident;
    public List<ConstExpTree> dimensions = new ArrayList<>();
    public InitValTree initVal;
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("IDENFR "+ident);

        for (var dim : dimensions) {
            printStream.println("LBRACK [");

            dim.walk(printStream);

            printStream.println("RBRACK ]");
        }

        if (initVal != null) {
            printStream.println("ASSIGN =");
            initVal.walk(printStream);
        }

        printStream.println("<VarDef>");
    }

    @Override
    public String getType() {
        return "VarDef";
    }
}
