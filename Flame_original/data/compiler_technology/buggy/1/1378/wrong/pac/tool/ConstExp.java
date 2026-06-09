package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class ConstExp implements Label {
    private Label val;
    private int line;
    private boolean err;

    public ConstExp(Lex lex) {
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
        out.println("<ConstExp>");
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
