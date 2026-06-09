package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class UnaryExp extends LabelList implements Label {
    public UnaryExp(Lex lex) {
        Label tmp = new UnaryOp(lex);
        if (!tmp.isErr()) {
            addList(tmp);
            tmp = new UnaryExp(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            } else {
                lex.pre();
                err = true;
            }
        } else if (lex.getFirst() == TOKEN.IDENFR && lex.getFirst(1) == TOKEN.LPARENT) {
            tmp = new Others(lex);
            addList(tmp);
            tmp = new Others(lex);
            addList(tmp);
            tmp = new FuncRParams(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
            if (lex.getFirst() != TOKEN.RPARENT) {
                error.put(tmp.getLine(), 'j');
            } else {
                tmp = new Others(lex);
                addList(tmp);
            }
        } else {
            tmp = new PrimaryExp(lex);
            if (tmp.isErr()) {
                err = true;
                return;
            }
            addList(tmp);
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<UnaryExp>");
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
