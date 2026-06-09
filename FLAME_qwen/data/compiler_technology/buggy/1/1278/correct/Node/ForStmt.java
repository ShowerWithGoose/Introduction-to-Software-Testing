package Node;
import Tools.Token;
import Tools.WriteFile;
public class ForStmt extends Node {
    LVal lVal;
    Exp exp;
    Token assign;

    public ForStmt(int lineno, LVal lVal, Token assign, Exp exp) {
        super(lineno);
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    public void checkOut() {
        lVal.checkOut();
        WriteFile.MakeFile(assign.toString() + "\n");
        exp.checkOut();
        WriteFile.MakeFile("<ForStmt>\n");
    }

}
