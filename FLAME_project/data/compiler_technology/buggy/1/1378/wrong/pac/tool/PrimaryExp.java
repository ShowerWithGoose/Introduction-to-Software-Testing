package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class PrimaryExp extends LabelList implements Label {
    public PrimaryExp(Lex lex) {
        Label tmp;
        if (lex.getFirst() == TOKEN.LPARENT) {
            tmp = new Others(lex);
            addList(tmp);
            tmp = new Exp(lex);
            if (tmp.isErr()) {
                lex.pre();
                err = true;
                return;
            }
            addList(tmp);
            if (lex.getFirst() != TOKEN.RPARENT) {
                error.put(line.get(line.size() - 1), 'j');
            } else {
                tmp = new Others(lex);
                addList(tmp);
            }
        } else {
            tmp = new LVal(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            } else if (lex.getFirst() == TOKEN.INTCON) {
                addList(new Number(lex));
            } else if (lex.getFirst() == TOKEN.CHRCON) {
                addList(new Char(lex));
            } else {
                err = true;
            }
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<PrimaryExp>");
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
