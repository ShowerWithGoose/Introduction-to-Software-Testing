package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public interface Label {
    void print(PrintStream out);

    int getLine();

    TreeMap<Integer, Character> getError();

    boolean isErr();
}
