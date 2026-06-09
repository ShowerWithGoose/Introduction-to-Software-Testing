package Node;
import Tools.Token;
import Tools.WriteFile;
public class ConstExp extends Node {
    AddExp addExp;

    public ConstExp(int lineno, AddExp addExp) {
        super(lineno);
        this.addExp = addExp;
    }

    public void checkOut() {
        addExp.checkOut();
        WriteFile.MakeFile("<ConstExp>\n");
    }
}
