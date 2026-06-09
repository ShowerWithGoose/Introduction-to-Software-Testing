package Node;
import Tools.Token;
import Tools.WriteFile;
public class UnaryExp extends Node {
    Token l_token = null;
    Token r_token = null;
    PrimaryExp primaryExp;
    Ident ident;
    FuncRParams funcRParams;
    UnaryOp unaryOp;
    UnaryExp unaryExp;
    int num;

    public UnaryExp(int lineno, PrimaryExp primaryExp, Ident ident, Token l_token,
                    FuncRParams funcRParams, Token r_token,
                    UnaryOp unaryOp, UnaryExp unaryExp, int num) {
        super(lineno);
        this.num = num;
        switch (num) {
            case 1:
                this.primaryExp = primaryExp;
                break;
            case 2:
                this.ident = ident;
                this.l_token = l_token;
                this.funcRParams = funcRParams;
                this.r_token = r_token;
                break;
            case 3:
                this.unaryOp = unaryOp;
                this.unaryExp = unaryExp;
                break;
            default:
                WriteFile.MakeFile("UnaryExp ERROR\n");
        }
    }

    public void checkOut() {
        switch (num) {
            case 1:
                primaryExp.checkOut();
                break;
            case 2:
                ident.checkOut();
                WriteFile.MakeFile(l_token.toString() + "\n");
                if (funcRParams != null) {
                    funcRParams.checkOut();
                }
                WriteFile.MakeFile(r_token.toString() + "\n");
                break;
            case 3:
                unaryOp.checkOut();
                unaryExp.checkOut();
                break;
            default:
        }
        WriteFile.MakeFile("<UnaryExp>\n");
    }
}
