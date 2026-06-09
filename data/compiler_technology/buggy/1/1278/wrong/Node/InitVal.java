package Node;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;
public class InitVal extends Node {
    ArrayList<Exp> exps;
    StringConst str;
    int num;

    public InitVal(int lineno, ArrayList<Exp> exps, StringConst str, int num) {
        super(lineno);
        this.num = num;
        if (num == 3) {
            this.str = str;
        } else {
            this.exps = exps;
        }
    }

    public void checkOut() {
        if (num == 3) {
            str.checkOut();
        } else if (num == 1) {
            exps.get(0).checkOut();
        } else {
            int i = 0;
            boolean flag = false;
            WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            for (Exp exp : exps) {
                if (flag) {
                    WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                } else {
                    flag = true;
                }
                exp.checkOut();
            }
            WriteFile.MakeFile(tokens.get(i).toString() + "\n");
        }
        WriteFile.MakeFile("<InitVal>\n");
    }
}
