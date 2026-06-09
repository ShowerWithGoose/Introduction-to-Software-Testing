package pac.tool;

import java.io.PrintStream;

public class ConstDecl extends LabelList implements Label {

    public ConstDecl(Lex lex) {
        int pre = lex.getP();
        Label tmp;
        if (lex.getFirst() != TOKEN.CONSTTK) {
            err = true;
            return;
        }
        tmp = new Others(lex);
        addList(tmp);
        tmp = new BType(lex);
        if (tmp.isErr()) {
            err = true;
            lex.pre();
            return;
        }
        addList(tmp);
        tmp = new ConstDef(lex);
        if (tmp.isErr()) {
            err = true;
            lex.returnTo(pre);
            return;
        }
        addList(tmp);
        while (lex.getFirst() == TOKEN.COMMA) {
            addList(new Others(lex));
            addList(new ConstDef(lex));
        }
        if (lex.getFirst() != TOKEN.SEMICN) {
            error.put(line.get(line.size() - 1), 'i');
        } else {
            addList(new Others(lex));
        }
    }

    @Override
    public void print(PrintStream out) {
        for(Label val:list){
            val.print(out);
        }
        out.println("<ConstDecl>");
    }
}
