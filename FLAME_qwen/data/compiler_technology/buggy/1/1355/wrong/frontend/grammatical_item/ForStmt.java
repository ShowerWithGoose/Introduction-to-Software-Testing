package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class ForStmt {
    public LVal lVal;
    public String ASSIGN = "=";
    public Exp exp;

    public void print(FileWriter lw) throws IOException {
        if(lVal != null)
            lVal.print(lw);
        lw.write("ASSIGN " + ASSIGN + "\n");
        if(exp != null)
            exp.print(lw);
        lw.write("<ForStmt>\n");
    }
}
