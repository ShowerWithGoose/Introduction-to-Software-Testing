package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class Char implements Label{
    private Pair<TOKEN, String> val;
    private int line;
    private boolean err;

    public Char(Lex lex) {
        if (lex.getFirst() == TOKEN.CHRCON) {
            val = lex.get();
            line = lex.getLine();
            lex.next();
        } else {
            err = false;
        }
    }
    public void print(PrintStream out) {
        out.println(val.first + " " + val.second);
        out.println("<Character>");
    }

    @Override
    public int getLine() {
        return line;
    }

    @Override
    public TreeMap<Integer, Character> getError() {
        return null;
    }

    @Override
    public boolean isErr() {
        return err;
    }
}
