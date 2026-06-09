package Node;
import Tools.Token;
import Tools.WriteFile;
public class Cond extends Node {
    LOrExp lOrExp;

    public Cond(int lineno, LOrExp lOrExp) {
        super(lineno);
        this.lOrExp = lOrExp;
    }

    public void checkOut() {
        lOrExp.checkOut();
        WriteFile.MakeFile("<Cond>\n");
    }
}
