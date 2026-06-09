package pac.tool;

import java.io.PrintStream;

public class FuncFParam extends LabelList implements Label {
    public FuncFParam(Lex lex) {
        int pre = lex.getP();
        Label tmp = new BType(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        addList(tmp);
        if (lex.getFirst() != TOKEN.IDENFR) {
            err = true;
            lex.returnTo(pre);
            return;
        }
        tmp = new Others(lex);
        addList(tmp);
        if (lex.getFirst() == TOKEN.LBRACK) {
            tmp = new Others(lex);
            addList(tmp);
            if (lex.getFirst() != TOKEN.RBRACK) {
                error.put(tmp.getLine(), 'k');
            } else {
                addList(new Others(lex));
            }
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<FuncFParam>");
    }
}
