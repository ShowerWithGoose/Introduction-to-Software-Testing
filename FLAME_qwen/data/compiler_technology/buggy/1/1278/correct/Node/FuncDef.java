package Node;
import Tools.Token;
import Tools.WriteFile;
public class FuncDef extends Node {
    Token l_token;
    Token r_token;
    FuncType funcType;
    Ident ident;
    FuncFParams funcFParams;
    Block block;

    public FuncDef(int lineno, FuncType funcType, Ident ident,
                   Token l_token, FuncFParams funcFParams, Token r_token,
                   Block block) {
        super(lineno);
        this.funcType = funcType;
        this.ident = ident;
        this.l_token = l_token;
        this.funcFParams = funcFParams;
        this.r_token = r_token;
        this.block = block;
    }

    public void checkOut() {
        funcType.checkOut();
        ident.checkOut();
        WriteFile.MakeFile(l_token.toString() + "\n");
        if (funcFParams != null) {
            funcFParams.checkOut();
        }
        WriteFile.MakeFile(r_token.toString() + "\n");
        block.checkOut();
        WriteFile.MakeFile("<FuncDef>\n");
    }

}
