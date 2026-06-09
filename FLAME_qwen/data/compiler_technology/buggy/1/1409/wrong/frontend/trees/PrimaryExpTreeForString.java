package frontend.trees;


import java.io.PrintStream;
import java.util.function.Consumer;

public class PrimaryExpTreeForString extends PrimaryExpTree {
    public StringTree string;

    @Override
    public void walk(PrintStream printStream) {
        string.walk(printStream);

        printStream.println("<PrimaryExp>");
    }
}
