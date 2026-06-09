package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDecl {
    public String CONSTTK;
    public String BType;
    public ArrayList<ConstDef> constDefs = new ArrayList<ConstDef>();
    public String SEMICN = ";";

    public void print(FileWriter lw) throws IOException {
        lw.write("CONSTTK " + CONSTTK + "\n");
        if(BType.equals("int"))
            lw.write("INTTK int\n");
        else if(BType.equals("char"))
            lw.write("CHARTK char\n");
        constDefs.get(0).print(lw);
        for(int i = 1;i < constDefs.size();i++) {
            lw.write("COMMA ,\n");
            constDefs.get(i).print(lw);
        }
        lw.write("SEMICN " + SEMICN + "\n");
        lw.write("<ConstDecl>\n");
    }
}
