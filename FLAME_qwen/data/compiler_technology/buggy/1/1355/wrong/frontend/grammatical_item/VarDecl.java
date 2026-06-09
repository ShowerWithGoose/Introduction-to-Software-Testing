package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDecl {
    public String BType;
    public ArrayList<VarDef> varDefs = new ArrayList<VarDef>();
    public String SEMICN = ";";

    public void print(FileWriter lw) throws IOException {
        if(BType.equals("int"))
            lw.write("INTTK int\n");
        else if(BType.equals("char"))
            lw.write("CHARTK char\n");
        varDefs.get(0).print(lw);
        for(int i = 1;i < varDefs.size();i++) {
            lw.write("COMMA ,\n");
            varDefs.get(i).print(lw);
        }
        lw.write("SEMICN " + SEMICN + "\n");
        lw.write("<VarDecl>\n");
    }
}
