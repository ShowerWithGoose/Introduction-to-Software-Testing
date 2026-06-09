package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncDef {
    public String funcType;
    public String ident;
    public String LPARENT;
    public ArrayList<FuncFParam> funcFParams = new ArrayList<FuncFParam>();
    public String RPARENT;
    public Block block;

    public void print(FileWriter lw) throws IOException {
        if(funcType.equals("void"))
            lw.write("VOIDTK " + funcType + "\n");
        else if(funcType.equals("int"))
            lw.write("INTTK " + funcType + "\n");
        else if(funcType.equals("char"))
            lw.write("CHARTK " + funcType + "\n");
        lw.write("<FuncType>\n");
        lw.write("IDENFR " + ident + "\n");
        lw.write("LPARENT " + LPARENT + "\n");
        if(!funcFParams.isEmpty()) {
            funcFParams.get(0).print(lw);
            for(int i = 1;i < funcFParams.size();i++) {
                lw.write("COMMA ,\n");
                funcFParams.get(i).print(lw);
            }
            lw.write("<FuncFParams>\n");
        }
        lw.write("RPARENT " + RPARENT + "\n");
        block.print(lw);
        lw.write("<FuncDef>\n");
    }
}
