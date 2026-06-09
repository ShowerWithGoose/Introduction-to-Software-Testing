package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MainFuncDef {
    public String INTTK;
    public String MAINTK;
    public String LPARENT;
    public String RPARENT;
    public Block block;

    public void print(FileWriter lw) throws IOException {
        lw.write("INTTK " + INTTK + "\n");
        lw.write("MAINTK " + MAINTK + "\n");
        lw.write("LPARENT " + LPARENT + "\n");
        lw.write("RPARENT " + RPARENT + "\n");
        block.print(lw);
        lw.write("<MainFuncDef>\n");
    }
}
