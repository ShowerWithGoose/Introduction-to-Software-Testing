package pac.tool;

import java.io.PrintStream;

public class Block extends LabelList implements Label {
    public Block(Lex lex) {
        int pre = lex.getP();
        if (lex.getFirst() != TOKEN.LBRACE) {
            err = true;
            return;
        }
        addList(new Others(lex));
        Label tmp = new BlockItem(lex);
        while (!tmp.isErr()) {
            addList(tmp);
            tmp = new BlockItem(lex);
        }
        if (lex.getFirst() != TOKEN.RBRACE) {
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(new Others(lex));
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<Block>");
    }
}
