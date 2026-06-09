package pac.tool;

import java.io.PrintStream;

public class FuncDef extends LabelList implements Label {
    public FuncDef(Lex lex) {
        int pre = lex.getP();
        Label tmp = new FuncType(lex);
        if (tmp.isErr()) {
            err = true;
            return;
        }
        addList(tmp);
        if (lex.getFirst() != TOKEN.IDENFR) {
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
        tmp = new FuncFParams(lex);
        if(!tmp.isErr()){
            addList(tmp);
        }
        if(lex.getFirst()!=TOKEN.RPARENT){
            error.put(line.get(line.size()-1),'j');
        }else{
            addList(new Others(lex));
        }
        tmp = new Block(lex);
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
        out.println("<FuncDef>");
    }
}
