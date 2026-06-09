package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class StmtTreeForContinueBreak extends StmtTree {
    public LexType type;
    public int tkLineNum = -1;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println(type+" "+type.get_LexType_s_value());
        printStream.println("SEMICN ;");

        printStream.println("<Stmt>");
    }
}
