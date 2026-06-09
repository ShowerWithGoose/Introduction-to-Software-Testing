package Node;
import Tools.Token;
import Tools.WriteFile;
public class RelExp extends Node {
    Token token;
    AddExp addExp;
    RelExp relExp;
    int num;

    public RelExp(int lineno, AddExp addExp, Token token, RelExp relExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.addExp = addExp;
        } else if (num == 2) {
            this.token = token;
            this.addExp = addExp;
            this.relExp = relExp;
        } else {
            WriteFile.MakeFile("RelExp ERROR\n");
        }
    }

    public void checkOut() {
        addExp.checkOut();
        WriteFile.MakeFile("<RelExp>\n");
        if (relExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            relExp.checkOut();
        }
    }
}
