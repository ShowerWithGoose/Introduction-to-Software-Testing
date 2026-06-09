package pac.tool;

import java.io.PrintStream;
import java.util.TreeMap;

public class Decl implements Label {
    private Label val;
    private int line;
    private boolean err;

    public Decl(Lex lex) {
        int pre = lex.getP();
        if (lex.getFirst() == TOKEN.CONSTTK) {
            val = new ConstDecl(lex);
            if (val.isErr()) {
                err = true;
                lex.returnTo(pre);
            }
        } else {
            val = new VarDecl(lex);
            if(val.isErr()){
                err=true;
                return;
            }
        }
        line=val.getLine();
    }

    @Override
    public void print(PrintStream out) {
        val.print(out);
    }

    @Override
    public int getLine() {
        return line;
    }

    @Override
    public TreeMap<Integer, Character> getError() {
        return val.getError();
    }

    @Override
    public boolean isErr() {
        return err;
    }
}
