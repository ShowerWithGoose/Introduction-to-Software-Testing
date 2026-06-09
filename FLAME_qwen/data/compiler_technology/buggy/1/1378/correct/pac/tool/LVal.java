package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class LVal extends LabelList implements Label {
    public LVal(Lex lex) {
        if (lex.getFirst() != TOKEN.IDENFR) {
            err = true;
            return;
        }
        Label tmp = new Others(lex);
        addList(tmp);
        if (lex.getFirst() == TOKEN.LBRACK) {
            tmp = new Others(lex);
            Label tmp1 = new Exp(lex);
            if (tmp1.isErr()) {
                lex.pre();
                return;
            }
            addList(tmp);
            addList(tmp1);
            if (lex.getFirst() != TOKEN.RBRACK) {
                error.put(tmp1.getLine(), 'k');
            } else {
                tmp = new Others(lex);
                addList(tmp);
            }
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<LVal>");
    }

    @Override
    public int getLine() {
        return line.get(line.size() - 1);
    }

    @Override
    public TreeMap<Integer, Character> getError() {
        return error;
    }

    @Override
    public boolean isErr() {
        return err;
    }
}
