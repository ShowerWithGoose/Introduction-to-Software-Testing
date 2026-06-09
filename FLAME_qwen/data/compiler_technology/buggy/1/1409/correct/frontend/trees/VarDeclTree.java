package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class VarDeclTree extends Tree {
    public BTypeTree type;
    public List<VarDefTree> varDefs = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        type.walk(printStream);

        boolean first = true;
        for (var varDef : varDefs) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            varDef.walk(printStream);
        }
        printStream.println("SEMICN ;");

        printStream.println("<VarDecl>");
    }

    @Override
    public String getType() {
        return "VarDecl";
    }
}
