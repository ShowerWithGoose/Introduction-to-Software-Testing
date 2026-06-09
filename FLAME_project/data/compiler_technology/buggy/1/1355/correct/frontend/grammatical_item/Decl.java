package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class Decl {
    public ConstDecl constDecl;
    public VarDecl varDecl;

    public void print(FileWriter lw) throws IOException {
        if(constDecl != null)
            constDecl.print(lw);
        if(varDecl != null)
            varDecl.print(lw);
    }
}
