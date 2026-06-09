package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class ConstExpTree extends Tree {
    public AddExpTree addExp;

    @Override
    public void walk(PrintStream printStream) {
        addExp.walk(printStream);

        printStream.println("<ConstExp>");
    }

    @Override
    public String getType() {
        return "ConstExp";
    }
}
