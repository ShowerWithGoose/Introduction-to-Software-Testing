package Node;
import Tools.Token;
import Tools.WriteFile;
public class PrimaryExp extends Node {
    Token l_token;
    Token r_token;
    Exp exp;
    LVal lVal;
    Num number;
    character cha;
    int num;

    public PrimaryExp(int lineno, Token l_token, Exp exp, Token r_token, LVal lVal, Num number, character cha, int num) {
        super(lineno);
        this.num = num;
        switch (num) {
            case 1:
                this.l_token = l_token;
                this.exp = exp;
                this.r_token = r_token;
                break;
            case 2:
                this.lVal = lVal;
                break;
            case 3:
                this.number = number;
                break;
            case 4:
                this.cha = cha;
                break;
            default:
                WriteFile.MakeFile("PrimaryExp ERROR\n");
        }
    }

    public void checkOut() {
        switch (num) {
            case 1:
                WriteFile.MakeFile(l_token.toString() + "\n");
                exp.checkOut();
                WriteFile.MakeFile(r_token.toString() + "\n");
                break;
            case 2:
                lVal.checkOut();
                break;
            case 3:
                number.checkOut();
                break;
            case 4:
                cha.checkOut();
                break;
            default:
                WriteFile.MakeFile("PrimaryExp ERROR\n");
        }
        WriteFile.MakeFile("<PrimaryExp>\n");
    }
}
