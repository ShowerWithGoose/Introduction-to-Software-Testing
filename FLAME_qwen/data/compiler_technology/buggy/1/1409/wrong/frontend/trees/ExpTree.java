package frontend.trees;

 

import java.io.PrintStream;
import java.util.function.Consumer;

public class ExpTree extends Tree {
    public AddExpTree addExp;

    @Override
    public void walk(PrintStream printStream) {
        addExp.walk(printStream);
        printStream.println("<Exp>");
    }

    @Override
    public String getType() {
        return "Exp";
    }
}
