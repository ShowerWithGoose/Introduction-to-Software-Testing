package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class FuncRParams extends LabelList implements Label {
    public FuncRParams(Lex lex) {
        Label tmp = new Exp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        list.add(tmp);
        line.add(tmp.getLine());
        error.putAll(tmp.getError());
        while (lex.getFirst() == TOKEN.COMMA) {
            tmp = new Others(lex);
            Label tmp1 = new Exp(lex);
            if (tmp1.isErr()) {
                lex.pre();
                return;
            }
            list.add(tmp);
            line.add(tmp.getLine());
            error.putAll(tmp.getError());
            list.add(tmp1);
            line.add(tmp1.getLine());
            error.putAll(tmp1.getError());
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<FuncRParams>");
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
