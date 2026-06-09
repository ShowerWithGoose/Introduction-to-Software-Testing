package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class PrimaryExpTreeForNumber extends PrimaryExpTree {
    public NumberTree number;

    @Override
    public void walk(PrintStream printStream) {
        number.walk(printStream);

        printStream.println("<PrimaryExp>");
    }
}
