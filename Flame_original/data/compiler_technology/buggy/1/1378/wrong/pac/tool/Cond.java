package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class Cond implements Label {
    private final Label val;
    private int line;
    private boolean err;

    public Cond(Lex lex) {
        val = new LOrExp(lex);
        if (val.isErr()) {
            err = true;
            return;
        }
        line = val.getLine();
    }

    @Override
    public void print(PrintStream out) {
        val.print(out);
        out.println("<Cond>");
    }

    @Override
    public int getLine() {
        return line;
    }

    @Override
    public TreeMap<Integer, Character> getError() {
        return val.getError();
    }

    @Override
    public boolean isErr() {
        return err;
    }
}
