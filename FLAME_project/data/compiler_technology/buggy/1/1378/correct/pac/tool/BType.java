package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class BType implements Label {
    private Pair<TOKEN, String> val;
    private int line;
    private boolean err;

    public BType(Lex lex) {
        if (lex.getFirst() == TOKEN.INTTK || lex.getFirst() == TOKEN.CHARTK) {
            val = lex.get();
            line = lex.getLine();
            lex.next();
            err = false;
        } else {
            err = true;
        }
    }

    public void print(PrintStream out) {
        out.println(val.first + " " + val.second);
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
