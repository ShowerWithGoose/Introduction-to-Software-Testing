package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class ConstDef {
    public String Ident;
    public String LBRACK;
    public ConstExp constExp;
    public String RBRACK;
    public String ASSIGN;
    public ConstInitVal constInitVal;

    public void print(FileWriter lw) throws IOException {
        lw.write("IDENFR " + Ident + "\n");
        if(LBRACK != null)
            lw.write("LBRACK " + LBRACK + "\n");
        if(constExp != null)
            constExp.print(lw);
        if(RBRACK != null)
            lw.write("RBRACK " + RBRACK + "\n");
        lw.write("ASSIGN " + ASSIGN + "\n");
        constInitVal.print(lw);
        lw.write("<ConstDef>\n");
    }
}
