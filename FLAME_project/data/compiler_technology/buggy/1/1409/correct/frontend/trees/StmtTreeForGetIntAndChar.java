package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForGetIntAndChar extends StmtTree {
    public LValTree lVal;

    public LexType type;

    @Override
    public void walk(PrintStream printStream) {
        lVal.walk(printStream);

        printStream.println("ASSIGN =");

        printStream.println(type+" "+type.get_LexType_s_value());

        printStream.println("LPARENT (");
        printStream.println("RPARENT )");
        printStream.println("SEMICN ;");

        printStream.println("<Stmt>");
    }
}
