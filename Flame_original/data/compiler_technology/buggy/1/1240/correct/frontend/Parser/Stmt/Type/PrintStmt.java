package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Exp;

import java.util.ArrayList;

public class PrintStmt implements StmtInter {
    // 'printf' '(' StringConst {','Exp}')'
    private final ArrayList<LexType> all; // printf + ( + string
    private final ArrayList<LexType> seps;
    private final ArrayList<Exp> exps;
    private final LexType right;

    public PrintStmt(ArrayList<LexType> all, ArrayList<LexType> seps,
                     ArrayList<Exp> exps, LexType right) {
        this.all = all;
        this.seps = seps;
        this.exps = exps;
        this.right = right;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(all.get(0)).append(all.get(1)).append(all.get(2));
        for (int i = 0; i < seps.size(); i++) {
            stringBuilder.append(seps.get(i)).append(exps.get(i));
        }
        stringBuilder.append(right);
        return stringBuilder.toString();
    }
}
