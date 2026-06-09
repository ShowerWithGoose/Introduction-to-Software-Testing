package Node;
import Tools.Token;
import Tools.WriteFile;
public class FuncFParam extends Node {
    BType bType;
    Ident ident;
    Token l_token;
    Token r_token;

    public FuncFParam(int lineno, BType bType, Ident ident,
                      Token l_token, Token r_token) {
        super(lineno);
        this.bType = bType;
        this.ident = ident;
        this.l_token = l_token;
        this.r_token = r_token;
    }

    public void checkOut() {
        bType.checkOut();
        ident.checkOut();
        if (l_token != null) {
            WriteFile.MakeFile(l_token.toString() + "\n");
            WriteFile.MakeFile(r_token.toString() + "\n");
        }
        WriteFile.MakeFile("<FuncFParam>\n");
    }
}
