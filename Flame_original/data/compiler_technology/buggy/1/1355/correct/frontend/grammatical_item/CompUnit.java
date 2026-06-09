package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CompUnit {
    public ArrayList<Decl> decls = new ArrayList<>();
    public ArrayList<FuncDef> funcDefs = new ArrayList<>();
    public MainFuncDef mainFuncDef;

    public void print(FileWriter lw) throws IOException {
        for(Decl decl : decls) {
            decl.print(lw);
        }
        for(FuncDef funcDef : funcDefs) {
            funcDef.print(lw);
        }
        mainFuncDef.print(lw);
        lw.write("<CompUnit>\n");
    }
}
