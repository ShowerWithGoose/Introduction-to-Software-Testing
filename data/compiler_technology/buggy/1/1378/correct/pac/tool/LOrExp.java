package pac.tool;

import java.io.PrintStream;

public class LOrExp extends LabelList implements Label{
    public LOrExp(Lex lex) {
        Label tmp = new LAndExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        Others tmp1, tmp3;
        LAndExp tmp2, tmp4;
        if (lex.getFirst() != TOKEN.OR) {
            addList(tmp);
            return;
        }
        tmp1 = new Others(lex);
        tmp2 = new LAndExp(lex);
        if (tmp2.isErr()) {
            lex.pre();
            addList(tmp);
            return;
        }
        tmp = new LOrExp((LAndExp) tmp);
        while (lex.getFirst() == TOKEN.OR) {
            tmp3 = new Others(lex);
            tmp4 = new LAndExp(lex);
            if (tmp4.isErr()) {
                lex.pre();
                addList(tmp);
                addList(tmp1);
                addList(tmp2);
                return;
            }
            tmp = new LOrExp((LOrExp) tmp, tmp1, tmp2);
            tmp1 = tmp3;
            tmp2 = tmp4;
        }
        addList(tmp);
        addList(tmp1);
        addList(tmp2);
    }

    public LOrExp(LAndExp tmp) {
        addList(tmp);
    }

    public LOrExp(LOrExp tmp1, Others tmp2, LAndExp tmp3) {
        addList(tmp1);
        addList(tmp2);
        addList(tmp3);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<LOrExp>");
    }
}
