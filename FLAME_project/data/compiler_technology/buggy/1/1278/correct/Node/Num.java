package Node;
import Tools.Token;
import Tools.WriteFile;
public class Num extends Node {
    Token num;

    public Num(int lineno, Token num) {
        super(lineno);
        this.num = num;
    }

    public void checkOut() {
        WriteFile.MakeFile(num.toString() + "\n");
        WriteFile.MakeFile("<Number>\n");
    }
}
