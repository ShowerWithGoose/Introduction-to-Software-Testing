package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class StmtTreeForPrintf extends StmtTree {
    public String formatString;
    public List<ExpTree> exps = new ArrayList<>();
    public int printfLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("PRINTFTK printf");
        printStream.println("LPARENT (");
        printStream.println("STRCON "+formatString);

        for (var exp : exps) {
            printStream.println("COMMA ,");
            exp.walk(printStream);
        }

        printStream.println("RPARENT )");
        printStream.println("SEMICN ;");

        printStream.println("<Stmt>");
    }
}
