package Node;
import Tools.WriteFile;
import Tools.Token;
import Tools.WriteFile;
import java.util.ArrayList;


public class FuncFParams extends Node {
    ArrayList<FuncFParam> funcFParams;

    public FuncFParams(int lineno, ArrayList<FuncFParam> funcFParams) {
        super(lineno);
        this.funcFParams = funcFParams;
    }

    public void checkOut() {
        int i = 0;
        boolean flag = false;
        for (FuncFParam funcFParam : funcFParams) {
            if (flag) {
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
            } else {
                flag = true;
            }
            funcFParam.checkOut();
        }
        WriteFile.MakeFile("<FuncFParams>\n");
    }
}
