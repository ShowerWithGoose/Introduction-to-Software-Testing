package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class Others implements Label {
    private Pair<TOKEN, String> val;
    private int line;

    public Others(Lex lex) {
        val = lex.get();
        line = lex.getLine();
        lex.next();
    }

    public void print(PrintStream out) {
        out.println(val.first + " " + val.second);
    }

    public int getLine() {
        return line;
    }

    public TreeMap<Integer, Character> getError() {
        return new TreeMap<>();
    }

    @Override
    public boolean isErr() {
        return false;
    }
}
