package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class ConstDeclTree extends Tree {
    public BTypeTree type;
    public List<ConstDefTree> constDefs = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("CONSTTK const");
        type.walk(printStream);
        boolean first = true;
        for (var constDef : constDefs) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            constDef.walk(printStream);
        }
        printStream.println("SEMICN ;");
        printStream.println("<ConstDecl>");
    }

    @Override
    public String getType() {
        return "ConstDecl";
    }
}
