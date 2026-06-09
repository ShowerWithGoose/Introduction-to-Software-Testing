package Node;
import Tools.Token;
import Tools.WriteFile;
public class UnaryOp extends Node {
    Token token;

    public UnaryOp(int lineno, Token token) {
        super(lineno);
        this.token = token;
    }

    public void checkOut() {
        WriteFile.MakeFile(token.toString() + "\n");
        WriteFile.MakeFile("<UnaryOp>\n");
    }
}
