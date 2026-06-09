package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class ConstInitValTreeForConstExp extends ConstInitValTree {
    public ConstExpTree constExp;

    @Override
    public void walk(PrintStream printStream) {
        constExp.walk(printStream);
        printStream.println("<ConstInitVal>");
    }
}
