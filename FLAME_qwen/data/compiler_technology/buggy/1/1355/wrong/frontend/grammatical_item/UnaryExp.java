package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryExp {
    public PrimaryExp primaryExp;
    public String Ident;
    public String LPARENT;
    public ArrayList<Exp> exps = new ArrayList<Exp>();
    public String RPARENT;
    public String unaryOp;
    public UnaryExp unaryExp;

    public void print(FileWriter lw) throws IOException {
        if(unaryOp != null) {
            if(unaryOp.equals("+"))
                lw.write("PLUS +\n");
            else if(unaryOp.equals("-"))
                lw.write("MINU -\n");
            else if(unaryOp.equals("!"))
                lw.write("NOT !\n");
            lw.write("<UnaryOp>\n");
            if(unaryExp != null)
                unaryExp.print(lw);
        }
        else if(Ident != null) {
            lw.write("IDENFR " + Ident + "\n");
            if(LPARENT != null)
                lw.write("LPARENT " + LPARENT + "\n");
            if(!exps.isEmpty()) {
                exps.get(0).print(lw);
                for(int i = 1;i < exps.size();i++) {
                    lw.write("COMMA ,\n");
                    exps.get(i).print(lw);
                }
                lw.write("<FuncRParams>\n");
            }
            if(RPARENT != null)
                lw.write("RPARENT " + RPARENT + "\n");
        }
        else if(primaryExp != null) {
            primaryExp.print(lw);
        }
        lw.write("<UnaryExp>\n");
    }
}
