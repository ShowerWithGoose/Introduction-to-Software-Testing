package Node;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;
public class ConstDecl extends Node {
    BType bType;
    ArrayList<ConstDef> constDefs;

    public ConstDecl(int lineno, BType bType, ArrayList<ConstDef> constDefs) {
        super(lineno);
        this.bType = bType;
        this.constDefs = constDefs;
    }

    public void checkOut() {
        int i = 0;
        boolean flag = false;
        WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
        bType.checkOut();
        for (ConstDef constDef : constDefs) {
            if (flag) {
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            } else {
                flag = true;
            }
            constDef.checkOut();
        }
        WriteFile.MakeFile(tokens.get(i).toString() + "\n");
        WriteFile.MakeFile("<ConstDecl>\n");
    }
}
