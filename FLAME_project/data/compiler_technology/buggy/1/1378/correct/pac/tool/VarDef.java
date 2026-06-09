package pac.tool;

import java.io.PrintStream;

public class VarDef extends LabelList implements Label {
    public VarDef(Lex lex) {
        if (lex.getFirst() != TOKEN.IDENFR) {
            err = true;
            return;
        }
        int pre = lex.getP();
        Label tmp = new Others(lex);
        addList(tmp);
        if(lex.getFirst()==TOKEN.LPARENT){
            lex.returnTo(pre);
            err = true;
            return;
        }
        if (lex.getFirst() == TOKEN.LBRACK) {
            addList(new Others(lex));
            tmp = new ConstExp(lex);
            if (tmp.isErr()) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(tmp);
            if (lex.getFirst() != TOKEN.RBRACK) {
                error.put(tmp.getLine(), 'k');
            } else {
                addList(new Others(lex));
            }
        }
        if(lex.getFirst()==TOKEN.ASSIGN){
            addList(new Others(lex));
            tmp = new InitVal(lex);
            if(tmp.isErr()){
                err=true;
                lex.returnTo(pre);
                return;
            }
            addList(tmp);
        }
    }

    @Override
    public void print(PrintStream out) {
        for(Label val:list){
            val.print(out);
        }
        out.println("<VarDef>");
    }
}
