package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class Exp implements Label {
    private Label val;
    private int line;
    private boolean err;

    public Exp(Lex lex) {
        Label tmp = new AddExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        val = tmp;
        line = tmp.getLine();
    }

    @Override
    public void print(PrintStream out) {
        val.print(out);
        out.println("<Exp>");
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
