package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class UnaryOp implements Label {
    private Pair<TOKEN, String> val;
    private int line;
    private boolean err;

    public UnaryOp(Lex lex) {
        Pair<TOKEN, String> tmp = lex.get();
        if (tmp.first == TOKEN.PLUS || tmp.first == TOKEN.MINU || tmp.first == TOKEN.NOT) {
            val = lex.get();
            line = lex.getLine();
            lex.next();
        } else {
            err = true;
        }
    }

    public void print(PrintStream out) {
        out.println(val.first + " " + val.second);
        out.println("<UnaryOp>");
    }

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
