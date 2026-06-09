package Node;
import Tools.Token;
import Tools.WriteFile;
public class LOrExp extends Node {
    Token token;
    LAndExp lAndExp;
    LOrExp lOrExp;
    int num;

    public LOrExp(int lineno, LAndExp lAndExp, Token token, LOrExp lOrExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.lAndExp = lAndExp;
        } else if (num == 2) {
            this.token = token;
            this.lOrExp = lOrExp;
            this.lAndExp = lAndExp;
        } else {
            WriteFile.MakeFile("LOrExp ERROR\n");
        }
    }

    public void checkOut() {
        lAndExp.checkOut();
        WriteFile.MakeFile("<LOrExp>\n");
        if (lOrExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            lOrExp.checkOut();
        }
    }
}
