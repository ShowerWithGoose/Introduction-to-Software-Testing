package pac.tool;

import java.io.PrintStream;

public class MainFuncDef extends LabelList implements Label {
    public MainFuncDef(Lex lex) {
        int pre = lex.getP();
        Label tmp;
        if (lex.getFirst() != TOKEN.INTTK) {
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(new Others(lex));
        if (lex.getFirst() != TOKEN.MAINTK) {
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(new Others(lex));
        if (lex.getFirst() != TOKEN.LPARENT) {
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(new Others(lex));
        if (lex.getFirst() != TOKEN.RPARENT) {
            error.put(line.get(line.size() - 1), 'j');
        } else {
            addList(new Others(lex));
        }
        tmp = new Block(lex);
        if (tmp.isErr()) {
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(tmp);
    }

    @Override
    public void print(PrintStream out) {
        for(Label val:list){
            val.print(out);
        }
        out.println("<MainFuncDef>");
    }
}
