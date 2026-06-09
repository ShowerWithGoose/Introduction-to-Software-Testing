package pac.tool;

import java.io.PrintStream;

public class EqExp extends LabelList implements Label{
    public EqExp(Lex lex) {
        Label tmp = new RelExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        Others tmp1, tmp3;
        RelExp tmp2, tmp4;
        if (lex.getFirst() != TOKEN.EQL && lex.getFirst() != TOKEN.NEQ) {
            addList(tmp);
            return;
        }
        tmp1 = new Others(lex);
        tmp2 = new RelExp(lex);
        if (tmp2.isErr()) {
            lex.pre();
            addList(tmp);
            return;
        }
        tmp = new EqExp((RelExp) tmp);
        while (lex.getFirst() == TOKEN.EQL || lex.getFirst() == TOKEN.NEQ) {
            tmp3 = new Others(lex);
            tmp4 = new RelExp(lex);
            if (tmp4.isErr()) {
                lex.pre();
                addList(tmp);
                addList(tmp1);
                addList(tmp2);
                return;
            }
            tmp = new EqExp((EqExp) tmp, tmp1, tmp2);
            tmp1 = tmp3;
            tmp2 = tmp4;
        }
        addList(tmp);
        addList(tmp1);
        addList(tmp2);
    }

    public EqExp(RelExp tmp) {
        addList(tmp);
    }

    public EqExp(EqExp tmp1, Others tmp2, RelExp tmp3) {
        addList(tmp1);
        addList(tmp2);
        addList(tmp3);
    }

    @Override
    public void print(PrintStream out) {
        for(Label val:list){
            val.print(out);
        }
        out.println("<EqExp>");
    }
}
