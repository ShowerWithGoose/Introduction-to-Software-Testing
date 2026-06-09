package Node;
import Tools.Token;
import Tools.WriteFile;
public class Decl extends Node {
    ConstDecl constDecl;
    VarDecl varDecl;

    public Decl(int lineno, Node node) {
        super(lineno);
        if (node instanceof ConstDecl) {
            this.constDecl = (ConstDecl) node;
        } else if (node instanceof VarDecl) {
            this.varDecl = (VarDecl) node;
        } else {
            WriteFile.MakeFile("Decl Error\n");
        }
    }

    public void checkOut() {
        if (constDecl != null) {
            constDecl.checkOut();
        } else {
            varDecl.checkOut();
        }
        //Tools.WriteFile.MakeFile("<Decl>");
    }
}
