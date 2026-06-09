package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;
import java.util.function.Consumer;

public class ForStmtTree extends Tree {
    public LValTree lVal;
    public ExpTree exp;

    @Override
    public void walk(PrintStream printStream) {
        lVal.walk(printStream);

        printStream.println("ASSIGN =");

        exp.walk(printStream);

        printStream.println("<ForStmt>");
    }

    @Override
    public String getType() {
        return "ForStmt";
    }
}
