package pac.tool;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.TreeMap;

public class ConstDef extends LabelList implements Label {

    public ConstDef(Lex lex) {
        int pre = lex.getP();
        Label tmp;
        if (lex.getFirst() != TOKEN.IDENFR) {
            err = true;
            return;
        }
        tmp = new Others(lex);
        addList(tmp);
        if (lex.getFirst() == TOKEN.LBRACK) {
            tmp = new Others(lex);
            addList(tmp);
            tmp = new ConstExp(lex);
            if (tmp.isErr()) {
                err = true;
                lex.pre();
                return;
            }
            addList(tmp);
            if (lex.getFirst() != TOKEN.RBRACK) {
                error.put(tmp.getLine(), 'k');
            } else {
                tmp = new Others(lex);
                addList(tmp);
            }
        }
        if (lex.getFirst() != TOKEN.ASSIGN) {
            err = true;
            lex.returnTo(pre);
            return;
        }
        tmp = new Others(lex);
        addList(tmp);
        tmp = new ConstInitVal(lex);
        if (tmp.isErr()) {
            err = true;
            lex.returnTo(pre);
        }
        addList(tmp);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<ConstDef>");
    }

    @Override
    public int getLine() {
        return line.get(line.size() - 1);
    }
}
