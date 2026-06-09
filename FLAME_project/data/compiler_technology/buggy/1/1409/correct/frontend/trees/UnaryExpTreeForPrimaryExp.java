package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class UnaryExpTreeForPrimaryExp extends UnaryExpTree {
    public PrimaryExpTree primaryExp;

    @Override
    public void walk(PrintStream printStream) {
        primaryExp.walk(printStream);

        printStream.println("<UnaryExp>");
    }
}
