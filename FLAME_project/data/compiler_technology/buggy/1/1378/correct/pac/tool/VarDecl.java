package pac.tool;

import java.io.PrintStream;

public class VarDecl extends LabelList implements Label {
    public VarDecl(Lex lex) {
        int pre = lex.getP();
        Label tmp = new BType(lex);
        if (tmp.isErr()) {
            err = true;
            lex.returnTo(pre);
            return;
        }
        addList(tmp);
        tmp = new VarDef(lex);
        if (tmp.isErr()) {
            err = true;
            lex.returnTo(pre);
            return;
        }
        addList(tmp);
        while (lex.getFirst() == TOKEN.COMMA) {
            addList(new Others(lex));
            addList(new VarDef(lex));
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
        out.println("<VarDecl>");
    }
}
