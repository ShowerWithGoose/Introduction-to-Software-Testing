package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class VarDef {
    public String Ident;
    public String LBRACK;
    public ConstExp constExp;
    public String RBRACK;
    public String ASSIGN;
    public InitVal initVal;

    public void print(FileWriter lw) throws IOException {
        if(Ident != null)
            lw.write("IDENFR " + Ident + "\n");
        if(LBRACK != null)
            lw.write("LBRACK " + LBRACK + "\n");
        if(constExp != null)
            constExp.print(lw);
        if(RBRACK != null)
            lw.write("RBRACK " + RBRACK + "\n");
        if(ASSIGN != null) {
            lw.write("ASSIGN " + ASSIGN + "\n");
            initVal.print(lw);
        }
        lw.write("<VarDef>\n");
    }
}
