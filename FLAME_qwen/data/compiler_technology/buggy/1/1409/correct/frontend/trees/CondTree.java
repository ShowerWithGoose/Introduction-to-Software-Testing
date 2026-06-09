package frontend.trees;



import java.io.PrintStream;
import java.util.function.Consumer;

public class CondTree extends Tree {
    public LOrExpTree lOrExp;

    @Override
    public void walk(PrintStream printStream) {
        lOrExp.walk(printStream);
        printStream.println("<Cond>");
    }

    @Override
    public String getType() {
        return "Cond";
    }
}
