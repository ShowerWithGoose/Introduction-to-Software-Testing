package pac.tool;

import java.io.PrintStream;

public class ConstInitVal extends LabelList implements Label {
    public ConstInitVal(Lex lex) {
        int pre = lex.getP();
        Label tmp;
        if (lex.getFirst() == TOKEN.STRCON) {
            tmp = new Others(lex);
            addList(tmp);
            return;
        }
        if (lex.getFirst() == TOKEN.LBRACE) {
            tmp = new Others(lex);
            addList(tmp);
            tmp = new ConstExp(lex);
            if (!tmp.isErr()) {
                addList(tmp);
                while (lex.getFirst() == TOKEN.COMMA) {
                    tmp = new Others(lex);
                    Label tmp1 = new ConstExp(lex);
                    if (tmp1.isErr()) {
                        lex.pre();
                        break;
                    }
                    addList(tmp);
                    addList(tmp1);
                }
            }
            if (lex.getFirst() != TOKEN.RBRACE) {
            } else {
                tmp = new Others(lex);
                addList(tmp);
            }
            return;
        }
        tmp = new ConstExp(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        addList(tmp);
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<ConstInitVal>");
    }

    @Override
    public int getLine() {
        return line.get(line.size() - 1);
    }
}
