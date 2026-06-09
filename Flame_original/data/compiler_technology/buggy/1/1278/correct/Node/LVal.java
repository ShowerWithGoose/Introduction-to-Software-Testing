package Node;
import Tools.Token;
import Tools.WriteFile;
public class LVal extends Node {
    Ident ident;
    Exp exp;
    Token l_token;
    Token r_token;

    public LVal(int lineno, Ident ident, Token l_token, Exp exp, Token r_token) {
        super(lineno);
        this.ident = ident;
        this.exp = exp;
        this.l_token = l_token;
        this.r_token = r_token;
    }

    public void checkOut() {
        ident.checkOut();
        if (exp != null) {
            WriteFile.MakeFile(l_token.toString() + "\n");
            exp.checkOut();
            WriteFile.MakeFile(r_token.toString() + "\n");
        }
        WriteFile.MakeFile("<LVal>\n");
    }
}
