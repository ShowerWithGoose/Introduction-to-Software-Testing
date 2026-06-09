package pac.tool;

import java.io.PrintStream;

public class MulExp extends LabelList implements Label {
    public MulExp(Lex lex) {
        Label tmp = new UnaryExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        Others tmp1, tmp3;
        UnaryExp tmp2, tmp4;
        if (lex.getFirst() != TOKEN.MULT && lex.getFirst() != TOKEN.DIV && lex.getFirst() != TOKEN.MOD) {
            addList(tmp);
            return;
        }
        tmp1 = new Others(lex);
        tmp2 = new UnaryExp(lex);
        if (tmp2.isErr()) {
            lex.pre();
            addList(tmp);
            return;
        }
        tmp = new MulExp((UnaryExp) tmp);
        while (lex.getFirst() == TOKEN.MULT || lex.getFirst() == TOKEN.DIV || lex.getFirst() == TOKEN.MOD) {
            tmp3 = new Others(lex);
            tmp4 = new UnaryExp(lex);
            if (tmp4.isErr()) {
                lex.pre();
                addList(tmp);
                addList(tmp1);
                addList(tmp2);
                return;
            }
            tmp = new MulExp((MulExp) tmp, tmp1, tmp2);
            tmp1 = tmp3;
            tmp2 = tmp4;
        }
        addList(tmp);
        addList(tmp1);
        addList(tmp2);
    }

    public MulExp(UnaryExp tmp) {
        addList(tmp);
    }

    public MulExp(MulExp tmp1, Others tmp2, UnaryExp tmp3) {
        addList(tmp1);
        addList(tmp2);
        addList(tmp3);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<MulExp>");
    }

    @Override
    public int getLine() {
        return line.get(line.size() - 1);
    }
}
