package Node;
import Tools.Token;
import Tools.WriteFile;
public class Ident extends Node {
    Token token;

    public Ident(int lineno, Token token) {
        super(lineno);
        this.token = token;
    }

    public void checkOut() {
        WriteFile.MakeFile(token.toString() + "\n");
        //Tools.WriteFile.MakeFile("<Ident>");
    }
}
