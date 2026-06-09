package frontend.trees;

import frontend.LexType;
 

import java.io.PrintStream;

public class PrimaryExpTreeForExp extends PrimaryExpTree {
    public ExpTree exp;

    @Override
    public void walk(PrintStream printStream) {
        printStream.println("LPARENT (");

        exp.walk(printStream);
        printStream.println("RPARENT )");


        printStream.println("<PrimaryExp>");
    }
}
