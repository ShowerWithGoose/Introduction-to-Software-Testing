package pac.tool;

import java.io.PrintStream;

public class FuncFParams extends LabelList implements Label{
    public FuncFParams(Lex lex){
        int pre =lex.getP();
        Label tmp = new FuncFParam(lex);
        if(tmp.isErr()){
            err=true;
            return;
        }
        addList(tmp);
        while(lex.getFirst()==TOKEN.COMMA){
            tmp=new Others(lex);
            Label tmp1=new FuncFParam(lex);
            if(tmp1.isErr()){
                lex.pre();
                return;
            }
            addList(tmp);
            addList(tmp1);
        }
    }

    @Override
    public void print(PrintStream out) {
        for(Label val:list){
            val.print(out);
        }
        out.println("<FuncFParams>");
    }
}
