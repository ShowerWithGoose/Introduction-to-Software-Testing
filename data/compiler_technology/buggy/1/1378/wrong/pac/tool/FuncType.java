package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class FuncType implements Label {
    private Pair<TOKEN, String> val;
    private int line;
    private boolean err;

    public FuncType(Lex lex) {
        if (lex.getFirst() == TOKEN.VOIDTK || lex.getFirst() == TOKEN.INTTK || lex.getFirst() == TOKEN.CHARTK) {
            val = lex.get();
            line = lex.getLine();
            lex.next();
        } else {
            err = true;
        }
    }

    @Override
    public void print(PrintStream out) {
        out.println(val.first+" "+val.second);
        out.println("<FuncType>");
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
