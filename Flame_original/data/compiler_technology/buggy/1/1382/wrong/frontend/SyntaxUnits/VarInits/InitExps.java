package frontend.SyntaxUnits.VarInits;

import frontend.SyntaxUnits.Exp;
import frontend.SyntaxUnits.Exps.ConstExp;

import java.util.ArrayList;

public class InitExps implements VarInitUnit {
    private final ArrayList<Exp> exps;

    public InitExps(ArrayList<Exp> exps) {
        this.exps = exps;
    }

    @Override
    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("LBRACE" + " {" +  "\n");
        if (! exps.isEmpty()) {
            for (Exp exp :  exps) {
                stringBuilder.append(exp.toPrint());
                stringBuilder.append("COMMA" + " ," +  "\n");
            }
            stringBuilder.delete(stringBuilder.length() - 8, stringBuilder.length());
        }
        stringBuilder.append("RBRACE" + " }" +  "\n");
        return stringBuilder.toString();
    }
}
