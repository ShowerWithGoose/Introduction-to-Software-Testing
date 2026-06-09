package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class InitVal {
    public Exp exp;
    public String LBRACE;
    public ArrayList<Exp> exps = new ArrayList<Exp>();
    public String RBRACE;
    public String StringConst;

    public void print(FileWriter lw) throws IOException {
        if(LBRACE != null) {
            lw.write("LBRACE " + LBRACE + "\n");
            if(!exps.isEmpty()) {
                exps.get(0).print(lw);
                for(int i = 1;i < exps.size();i++) {
                    lw.write("COMMA ,\n");
                    exps.get(i).print(lw);
                }
            }
            lw.write("RBRACE " + RBRACE + "\n");
        }
        else if(exp != null)
            exp.print(lw);
        else if(StringConst != null)
            lw.write("STRCON " + StringConst + "\n");
        lw.write("<InitVal>\n");
    }
}
