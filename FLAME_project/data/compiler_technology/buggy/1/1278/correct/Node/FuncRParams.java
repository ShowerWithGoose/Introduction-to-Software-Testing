package Node;
import Tools.Token;
import Tools.WriteFile;

import java.util.ArrayList;

public class FuncRParams extends Node {
    ArrayList<Exp> exps;

    public FuncRParams(int lineno, ArrayList<Exp> exps) {
        super(lineno);
        this.exps = exps;
    }

    public void checkOut() {
        int i = 0;
        boolean flag = false;
        for (Exp exp : exps) {
            if (flag) {
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            } else {
                flag = true;
            }
            exp.checkOut();
        }
        WriteFile.MakeFile("<FuncRParams>\n");
    }
}
