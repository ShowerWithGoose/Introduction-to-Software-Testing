package Node;
import Tools.Token;
import Tools.WriteFile;
public class ConstDef extends Node {
    Token l_token;
    Token r_token;
    Token assign_token;
    Ident ident;
    ConstExp constExp;
    ConstInitVal constInitVal;

    public ConstDef(int lineno, Ident ident, Token l_token, ConstExp constExp
            , Token r_token, Token assign_token, ConstInitVal constInitVal) {
        super(lineno);
        this.ident = ident;
        this.l_token = l_token;
        this.constExp = constExp;
        this.r_token = r_token;
        this.assign_token = assign_token;
        this.constInitVal = constInitVal;
    }

    public void checkOut() {
        ident.checkOut();
        if (constExp != null) {
            WriteFile.MakeFile(l_token.toString() + "\n");
            constExp.checkOut();
            WriteFile.MakeFile(r_token.toString() + "\n");
        }
        WriteFile.MakeFile(assign_token.toString() + "\n");
        constInitVal.checkOut();
        WriteFile.MakeFile("<ConstDef>\n");
    }
}
