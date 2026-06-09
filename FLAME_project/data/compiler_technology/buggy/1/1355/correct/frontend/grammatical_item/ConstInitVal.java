package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstInitVal {
    public ConstExp constExp;
    public String LBRACE;
    public ArrayList<ConstExp> constExps = new ArrayList<>();
    public String RBRACE;
    public String StringConst;

    public void print(FileWriter lw) throws IOException {
        if(constExp != null)
            constExp.print(lw);
        else if(LBRACE != null) {
            lw.write("LBRACE " + LBRACE + "\n");
            if(!constExps.isEmpty()) {
                constExps.get(0).print(lw);
                for(int i = 1;i < constExps.size();i++) {
                    lw.write("COMMA ,\n");
                    constExps.get(i).print(lw);
                }
            }
            lw.write("RBRACE " + RBRACE + "\n");
        }
        else if(StringConst != null)
            lw.write("STRCON " + StringConst + "\n");
        lw.write("<ConstInitVal>\n");
    }
}
