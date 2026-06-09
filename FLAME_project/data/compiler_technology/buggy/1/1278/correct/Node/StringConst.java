package Node;
import Tools.Token;
import Tools.WriteFile;
public class StringConst extends Node {
    Token str;

    public StringConst(int lineno, Token str) {
        super(lineno);
        this.str = str;
    }

    public void checkOut() {
        WriteFile.MakeFile(str.toString() + "\n");
        //Tools.WriteFile.MakeFile("<StringConst>");
    }
}
