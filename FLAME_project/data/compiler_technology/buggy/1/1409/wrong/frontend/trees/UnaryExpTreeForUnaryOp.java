package frontend.trees;

import java.io.PrintStream;

public class UnaryExpTreeForUnaryOp extends UnaryExpTree {
    public UnaryOpTree op;
    public UnaryExpTree exp;

    @Override
    public void walk(PrintStream printStream) {
        op.walk(printStream);

        exp.walk(printStream);

        printStream.println("<UnaryExp>");
    }
}
