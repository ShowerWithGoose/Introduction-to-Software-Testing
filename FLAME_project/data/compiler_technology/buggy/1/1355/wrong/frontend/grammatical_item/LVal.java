package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LVal {
    public String Ident;
    public String LBRACK;
    public Exp exp;
    public String RBRACK;

    public void print(FileWriter lw) throws IOException {
        if(Ident != null)
            lw.write("IDENFR " + Ident + "\n");
        if(LBRACK != null)
            lw.write("LBRACK " + LBRACK + "\n");
        if(exp != null)
            exp.print(lw);
        if(RBRACK != null)
            lw.write("RBRACK " + RBRACK + "\n");
        lw.write("<LVal>\n");
    }
}
