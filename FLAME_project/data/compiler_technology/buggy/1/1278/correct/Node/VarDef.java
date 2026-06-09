package Node;
import Tools.Token;
import Tools.WriteFile;
public class VarDef extends Node {
    Token l_token;
    Token r_token;
    Token assign_token;
    Ident ident;
    ConstExp constExp;
    InitVal initVal;
    int num;

    public VarDef(int lineno, Ident ident, Token l_token,
                  ConstExp constExp, Token r_token, Token assign_token,
                  InitVal initVal, int num) {
        super(lineno);
        this.ident = ident;
        this.l_token = l_token;
        this.constExp = constExp;
        this.r_token = r_token;
        this.assign_token = assign_token;
        this.initVal = initVal;
        this.num = num;
    }

    public void checkOut() {
        ident.checkOut();
        if (constExp != null) {
            WriteFile.MakeFile(l_token.toString() + "\n");
            constExp.checkOut();
            WriteFile.MakeFile(r_token.toString() + "\n");
        }
        if (num == 2) {
            WriteFile.MakeFile(assign_token.toString() + "\n");
            initVal.checkOut();
        }
        WriteFile.MakeFile("<VarDef>\n");
    }
}
