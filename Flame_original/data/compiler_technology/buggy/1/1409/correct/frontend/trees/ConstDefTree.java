package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class ConstDefTree extends Tree {
    public String ident;
    public List<ConstExpTree> dimensions = new ArrayList<>();
    public ConstInitValTree constInitVal;
    public int identLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("IDENFR "+ident);

        for (var dimension : dimensions) {
            printStream.println("LBRACK [");

            dimension.walk(printStream);

            printStream.println("RBRACK ]");
        }

        printStream.println("ASSIGN =");

        constInitVal.walk(printStream);

        printStream.println("<ConstDef>");
    }

    @Override
    public String getType() {
        return "ConstDef";
    }
}
