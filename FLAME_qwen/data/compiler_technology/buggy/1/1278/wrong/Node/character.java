package Node;
import Tools.Token;
import Tools.WriteFile;
public class character extends Node {
    Token cha;

    public character(int lineno, Token cha) {
        super(lineno);
        this.cha = cha;
    }

    public void checkOut() {
        WriteFile.MakeFile(cha.toString() + "\n");
        WriteFile.MakeFile("<Character>\n");
    }
}
