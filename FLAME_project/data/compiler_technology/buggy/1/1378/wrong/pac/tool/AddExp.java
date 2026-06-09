package pac.tool;

import java.io.PrintStream;

public class AddExp extends LabelList implements Label {
    public AddExp(Lex lex) {
        Label tmp = new MulExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        Others tmp1, tmp3;
        MulExp tmp2, tmp4;
        if (lex.getFirst() != TOKEN.PLUS && lex.getFirst() != TOKEN.MINU) {
            addList(tmp);
            return;
        }
        tmp1 = new Others(lex);
        tmp2 = new MulExp(lex);
        if (tmp2.isErr()) {
            lex.pre();
            addList(tmp);
            return;
        }
        tmp = new AddExp((MulExp) tmp);
        while (lex.getFirst() == TOKEN.PLUS || lex.getFirst() == TOKEN.MINU) {
            tmp3 = new Others(lex);
            tmp4 = new MulExp(lex);
            if (tmp4.isErr()) {
                lex.pre();
                addList(tmp);
                addList(tmp1);
                addList(tmp2);
                return;
            }
            tmp = new AddExp((AddExp) tmp, tmp1, tmp2);
            tmp1 = tmp3;
            tmp2 = tmp4;
        }
        addList(tmp);
        addList(tmp1);
        addList(tmp2);
    }

    public AddExp(MulExp tmp) {
        addList(tmp);
    }

    public AddExp(AddExp tmp1, Others tmp2, MulExp tmp3) {
        addList(tmp1);
        addList(tmp2);
        addList(tmp3);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<AddExp>");
    }

    @Override
    public int getLine() {
        return line.get(line.size() - 1);
    }
}
