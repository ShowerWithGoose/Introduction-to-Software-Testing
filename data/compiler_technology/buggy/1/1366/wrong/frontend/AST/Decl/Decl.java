package frontend.AST.Decl;

import java.nio.file.Path;
import java.nio.file.Paths;

public class Decl {
    private int type;
    //Type = 1
    private ConstDecl constDecl;
    //2
    private VarDecl varDecl;

    public Decl(ConstDecl constDecl) {
        type = 1;
        this.constDecl = constDecl;
    }

    public Decl(VarDecl varDecl) {
        type = 2;
        this.varDecl = varDecl;
    }

    public void postorder() {
        if (type == 1) {
            constDecl.postorder();
        }
        else {
            varDecl.postorder();
        }

    }
    //Decl â†’ ConstDecl | VarDecl
}
