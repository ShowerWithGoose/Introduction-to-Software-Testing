package Node;
import Tools.Token;
import Tools.WriteFile;
public class AddExp extends Node {
    MulExp mulExp;
    AddExp addExp;
    Token token;
    int num;

    public AddExp(int lineno, MulExp mulExp, Token token, AddExp addExp, int num) {
        super(lineno);
        this.num = num;
        if (num == 1) {
            this.mulExp = mulExp;
        } else if (num == 2) {
            this.token = token;
            this.addExp = addExp;
            this.mulExp = mulExp;
        } else {
            WriteFile.MakeFile("AddExp ERROR\n");
        }
    }

    public void checkOut() {
        mulExp.checkOut();
        WriteFile.MakeFile("<AddExp>\n");
        if (addExp != null) {
            WriteFile.MakeFile(token.toString() + "\n");
            addExp.checkOut();
        }
    }
}
