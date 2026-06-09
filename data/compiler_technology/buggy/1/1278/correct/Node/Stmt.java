package Node;
import java.util.ArrayList;
import Tools.Token;
import Tools.WriteFile;
public class Stmt extends Node {
    LVal lVal;
    ArrayList<Exp> exps;
    Block block;
    Cond cond;
    Stmt stmt1;
    Stmt stmt2;
    ForStmt forStmt1;
    ForStmt forStmt2;
    StringConst str;
    int num;

    public Stmt(int lineno, LVal lVal, ArrayList<Exp> exps, Block block, Cond cond,
                Stmt stmt1, Stmt stmt2, ForStmt forStmt1, ForStmt forStmt2, StringConst str, int num) {
        super(lineno);
        this.num = num;
        switch (num) {
            case 1:
                this.lVal = lVal;
                this.exps = exps;
                break;
            case 2:
            case 8:
                this.exps = exps;
                break;
            case 3:
                this.block = block;
                break;
            case 4:
                this.cond = cond;
                this.stmt1 = stmt1;
                this.stmt2 = stmt2;
                break;
            case 5:
                this.forStmt1 = forStmt1;
                this.cond = cond;
                this.forStmt2 = forStmt2;
                this.stmt1 = stmt1;
                break;
            case 6:
            case 7:
                break;
            case 9:
            case 10:
                this.lVal = lVal;
                break;
            case 11:
                this.str = str;
                this.exps = exps;
                break;
            default:
                WriteFile.MakeFile(num + "Stmt ERROR\n");
        }

    }

    public void checkOut() {
        int i = 0;
        switch (num) {
            case 1:
                lVal.checkOut();
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                exps.get(0).checkOut();
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            case 2:
                for (Exp exp : exps) {
                    exp.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            case 3:
                block.checkOut();
                break;
            case 4:
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                cond.checkOut();
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                stmt1.checkOut();
                if (stmt2 != null) {
                    WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                    stmt2.checkOut();
                }
                break;
            case 5:
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                if (forStmt1 != null) {
                    forStmt1.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                if (cond != null) {
                    cond.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                if (forStmt2 != null) {
                    forStmt2.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                if (stmt1 != null) {
                    stmt1.checkOut();
                }
                break;
            case 6:
            case 7:
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            case 8:
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                for (Exp exp : exps) {
                    exp.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            case 9:
            case 10:
                lVal.checkOut();
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            case 11:
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                str.checkOut();
                for (Exp exp : exps) {
                    WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                    exp.checkOut();
                }
                WriteFile.MakeFile(tokens.get(i++).toString() + "\n");
                WriteFile.MakeFile(tokens.get(i).toString() + "\n");
                break;
            default:
        }
        WriteFile.MakeFile("<Stmt>\n");
    }
}
