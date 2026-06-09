package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class PrimaryExp {
    public String LPARENT;
    public Exp exp;
    public String RPARENT;
    public LVal lVal;
    public String Number;
    public String Character;

    public void print(FileWriter lw) throws IOException {
        if(Number != null) {
            lw.write("INTCON " + Number + "\n");
            lw.write("<Number>\n");
        }
        else if(Character != null) {
            lw.write("CHRCON " + Character + "\n");
            lw.write("<Character>\n");
        }
        else if(lVal != null) {
            lVal.print(lw);
        }
        else if(LPARENT != null) {
            lw.write("LPARENT " + LPARENT + "\n");
            if(exp != null)
                exp.print(lw);
            if(RPARENT != null)
                lw.write("RPARENT " + RPARENT + "\n");
        }
        lw.write("<PrimaryExp>\n");
    }
}
