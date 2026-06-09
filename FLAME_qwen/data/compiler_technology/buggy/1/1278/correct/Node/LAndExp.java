package Node;
import Tools.Token;
import Tools.WriteFile;
public class LAndExp extends Node {
    Token token;
    EqExp eqExp;
    LAndExp lAndExp;
    int num;

    public LAndExp(int lineno, EqExp eqExp, Token token, LAndExp lAndExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.eqExp = eqExp;
        } else if (num == 2) {
            this.token = token;
            this.eqExp = eqExp;
            this.lAndExp = lAndExp;
        } else {
            WriteFile.MakeFile("LAndExp ERROR\n");
        }
    }

    public void checkOut() {
        eqExp.checkOut();
        WriteFile.MakeFile("<LAndExp>\n");
        if (lAndExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            lAndExp.checkOut();
        }
    }
}
