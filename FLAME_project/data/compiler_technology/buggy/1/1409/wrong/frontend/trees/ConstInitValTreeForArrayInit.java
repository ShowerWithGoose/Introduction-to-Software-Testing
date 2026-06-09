package frontend.trees;

import frontend.LexType;
import frontend.Parser;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class ConstInitValTreeForArrayInit extends ConstInitValTree {
    public List<ConstExpTree> constExpTrees = new ArrayList<>();

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("LBRACE {");

        boolean first = true;
        for (var constexp : constExpTrees) {
            if (first) {
                first = false;
            } else {
                printStream.println("COMMA ,");
            }
            constexp.walk(printStream);
        }

        printStream.println("RBRACE }");
        printStream.println("<ConstInitVal>");
    }
}
