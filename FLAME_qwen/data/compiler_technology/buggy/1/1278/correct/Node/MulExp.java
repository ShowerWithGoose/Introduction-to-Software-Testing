package Node;
import Tools.Token;
import Tools.WriteFile;
public class MulExp extends Node {
    UnaryExp unaryExp;
    MulExp mulExp;
    Token token;
    int num;

    public MulExp(int lineno, UnaryExp unaryExp, Token token, MulExp mulExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.unaryExp = unaryExp;
        } else if (num == 2) {
            this.token = token;
            this.unaryExp = unaryExp;
            this.mulExp = mulExp;
        } else {
            WriteFile.MakeFile("MulExp ERROR\n");
        }
    }

    public void checkOut() {
        unaryExp.checkOut();
        WriteFile.MakeFile("<MulExp>\n");
        if (mulExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            mulExp.checkOut();
        }
    }
}
