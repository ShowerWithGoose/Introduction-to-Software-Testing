package Node;
import Tools.Token;
import Tools.WriteFile;
public class Exp extends Node {
    AddExp addExp;

    public Exp(int lineno, AddExp addExp) {
        super(lineno);
        this.addExp = addExp;
    }

    public void checkOut() {
        addExp.checkOut();
        WriteFile.MakeFile("<Exp>\n");
    }
}
