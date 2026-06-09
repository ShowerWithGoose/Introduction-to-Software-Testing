package pac.tool;

import java.io.PrintStream;

public class LAndExp extends LabelList implements Label{
    public LAndExp(Lex lex) {
        Label tmp = new EqExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        Others tmp1, tmp3;
        EqExp tmp2, tmp4;
        if (lex.getFirst() != TOKEN.AND) {
            addList(tmp);
            return;
        }
        tmp1 = new Others(lex);
        tmp2 = new EqExp(lex);
        if (tmp2.isErr()) {
            lex.pre();
            addList(tmp);
            return;
        }
        tmp = new LAndExp((EqExp) tmp);
        while (lex.getFirst() == TOKEN.AND) {
            tmp3 = new Others(lex);
            tmp4 = new EqExp(lex);
            if (tmp4.isErr()) {
                lex.pre();
                addList(tmp);
                addList(tmp1);
                addList(tmp2);
                return;
            }
            tmp = new LAndExp((LAndExp) tmp, tmp1, tmp2);
            tmp1 = tmp3;
            tmp2 = tmp4;
        }
        addList(tmp);
        addList(tmp1);
        addList(tmp2);
    }

    public LAndExp(EqExp tmp) {
        addList(tmp);
    }

    public LAndExp(LAndExp tmp1, Others tmp2, EqExp tmp3) {
        addList(tmp1);
        addList(tmp2);
        addList(tmp3);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<LAndExp>");
    }
}
