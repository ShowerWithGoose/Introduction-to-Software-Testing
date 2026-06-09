package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class FuncFParam {
    public String BType;
    public String Ident;
    public String LBRACK;
    public String RBRACK;

    public void print(FileWriter lw) throws IOException {
        if(BType.equals("int"))
            lw.write("INTTK int\n");
        else if(BType.equals("char"))
            lw.write("CHARTK char\n");
        lw.write("IDENFR " + Ident + "\n");
        if(LBRACK != null)
            lw.write("LBRACK " + LBRACK + "\n");
        if(RBRACK != null)
            lw.write("RBRACK " + RBRACK + "\n");
        lw.write("<FuncFParam>\n");
    }
}
