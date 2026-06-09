package pac.tool;

import java.io.PrintStream;

public class CompUnit extends LabelList implements Label {

    public CompUnit(Lex lex) {
        Label tmp;
        int pre = lex.getP();
        do {
            tmp = new Decl(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
        } while (!tmp.isErr());
        do {
            tmp = new FuncDef(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
        } while (!tmp.isErr());
        tmp = new MainFuncDef(lex);
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
        out.println("<CompUnit>");
    }
}
