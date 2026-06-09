package frontend.trees;


import java.io.PrintStream;
import java.util.function.Consumer;

public class ConstInitValTreeForStringConst extends ConstInitValTree {
    public StringTree string;

    @Override
    public void walk(PrintStream printStream) {
        string.walk(printStream);
        printStream.println("<ConstInitVal>");
    }
}
