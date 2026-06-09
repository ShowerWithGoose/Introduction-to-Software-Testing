package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class BlockItem implements Label {
    private Label val;
    private int line;
    private boolean err;

    public BlockItem(Lex lex) {
        Label tmp = new Decl(lex);
        if (!tmp.isErr()) {
            val = tmp;
            line = tmp.getLine();
        } else {
            tmp = new Stmt(lex);
            if (tmp.isErr()) {
                err = true;
                return;
            }
            val = tmp;
            line = tmp.getLine();
        }
    }

    @Override
    public void print(PrintStream out) {
        val.print(out);
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
