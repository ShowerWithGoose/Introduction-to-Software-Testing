package Node;
import Tools.Token;
import Tools.WriteFile;
public class FuncType extends Node {
    Token token;

    public FuncType(int lineno, Token token) {
        super(lineno);
        this.token = token;
    }

    public void checkOut() {
        WriteFile.MakeFile(token.toString() + "\n");
        WriteFile.MakeFile("<FuncType>\n");
    }
}
