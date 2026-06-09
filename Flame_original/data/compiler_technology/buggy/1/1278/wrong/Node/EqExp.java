package Node;
import Tools.Token;
import Tools.WriteFile;
public class EqExp extends Node {
    Token token;
    RelExp relExp;
    EqExp eqExp;
    int num;

    public EqExp(int lineno, RelExp relExp, Token token, EqExp eqExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.relExp = relExp;
        } else if (num == 2) {
            this.token = token;
            this.eqExp = eqExp;
            this.relExp = relExp;
        } else {
            WriteFile.MakeFile("EqExp ERROR\n");
        }
    }

    public void checkOut() {
        relExp.checkOut();
        WriteFile.MakeFile("<EqExp>\n");
        if (eqExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            eqExp.checkOut();
        }
    }
}
