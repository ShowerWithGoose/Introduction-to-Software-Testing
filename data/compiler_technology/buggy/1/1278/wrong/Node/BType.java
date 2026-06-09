package Node;
import Tools.Token;
import Tools.WriteFile;
public class BType extends Node {
    Token token;

    public BType(int lineno, Token token) {
        super(lineno);
        this.token = token;
    }

    public void checkOut() {
        WriteFile.MakeFile(token.toString() + "\n");
        //Tools.WriteFile.MakeFile("<BType>");
    }
}
