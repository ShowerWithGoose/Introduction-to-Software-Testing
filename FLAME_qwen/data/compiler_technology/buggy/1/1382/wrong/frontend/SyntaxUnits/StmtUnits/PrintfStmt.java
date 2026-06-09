package frontend.SyntaxUnits.StmtUnits;

import frontend.SyntaxUnits.Exp;
import frontend.Token;


import java.util.ArrayList;

public class PrintfStmt implements StmtUnit{
    private final Token stringConst;
    private final ArrayList<Exp> exps;
    private final boolean hasExps;

    public PrintfStmt(Token stringConst) {
        this.stringConst = stringConst;
        exps = null;
        hasExps = false;
    }

    public PrintfStmt(Token stringConst, ArrayList<Exp> exps) {
        this.stringConst = stringConst;
        this.exps = exps;
        hasExps = true;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("PRINTFTK" + " printf" +  "\n");
        stringBuilder.append("LPARENT" + " (" +  "\n");
        stringBuilder.append(stringConst.toPrint());
        if (hasExps) {
            for (Exp exp : exps) {
                stringBuilder.append("COMMA" + " ," +  "\n");
                stringBuilder.append(exp.toPrint());
            }
        }
        stringBuilder.append("RPARENT" + " )" +  "\n");
        stringBuilder.append("SEMICN" + " ;" +  "\n");
        return stringBuilder.toString();
    }
}
