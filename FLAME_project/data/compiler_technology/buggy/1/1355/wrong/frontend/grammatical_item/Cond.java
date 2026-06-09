package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class Cond {
    public LOrExp lOrExp;

    public void print(FileWriter lw) throws IOException {
        if(lOrExp != null)
            lOrExp.print(lw);
        lw.write("<Cond>\n");
    }
}
