package tree;

import java.io.FileWriter;
import java.io.IOException;

public class Decl {
    private VarDecl varDecl;
    private ConstDecl constDecl;


    public void setVarDecl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }

    public void setConstDecl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (varDecl != null) {
            varDecl.output(fileWriter);
        } else {
            constDecl.output(fileWriter);
        }
    }
}
