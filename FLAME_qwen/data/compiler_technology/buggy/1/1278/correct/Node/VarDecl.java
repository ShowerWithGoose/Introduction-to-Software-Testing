package Node;
import java.util.ArrayList;
import Tools.Token;
import Tools.WriteFile;
public class VarDecl extends Node {
    BType bType;
    ArrayList<VarDef> varDefs;

    public VarDecl(int lineno, BType bType, ArrayList<VarDef> varDefs) {
        super(lineno);
        this.bType = bType;
        this.varDefs = varDefs;
    }

    public void checkOut() {
        int i = 0;
        boolean flag = false;
        bType.checkOut();
        for (VarDef varDef : varDefs) {
            if (flag) {
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            } else {
                flag = true;
            }
            varDef.checkOut();
        }
        WriteFile.MakeFile(tokens.get(i).toString() + "\n");
        WriteFile.MakeFile("<VarDecl>\n");
    }
}
