package pac.tool;

import java.io.PrintStream;

public class ForStmt extends LabelList implements Label {
    public ForStmt(Lex lex) {
        int pre =lex.getP();
        Label tmp = new LVal(lex);
        if(tmp.isErr()){
            err=true;
            return;
        }
        addList(tmp);
        if(lex.getFirst()!=TOKEN.ASSIGN){
            lex.returnTo(pre);
            err = true;
            return;
        }
        addList(new Others(lex));
        tmp=new Exp(lex);
        if(tmp.isErr()){
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
        out.println("<ForStmt>");
    }
}
