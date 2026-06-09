package Node;
import Tools.WriteFile;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;

public class ConstInitVal extends Node {
    ArrayList<ConstExp> constExps;
    StringConst stringConst;
    int num;

    public ConstInitVal(int lineno, ArrayList<ConstExp> constExps, StringConst stringConst, int num) {
        super(lineno);
        this.constExps = constExps;
        this.stringConst = stringConst;
        this.num = num;
    }

    public void checkOut() {
        if (num == 1) {
            for (ConstExp constExp : constExps) {
                constExp.checkOut();
            }
        } else if (num == 2) {
            int i = 0;
            boolean flag = false;
            WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            for (ConstExp constExp : constExps) {
                if (flag) {
                    WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                } else {
                    flag = true;
                }
                constExp.checkOut();
            }
            WriteFile.MakeFile(tokens.get(i).toString() + "\n");
        } else if (num == 3) {
            stringConst.checkOut();
        }
        WriteFile.MakeFile("<ConstInitVal>\n");
    }
}
