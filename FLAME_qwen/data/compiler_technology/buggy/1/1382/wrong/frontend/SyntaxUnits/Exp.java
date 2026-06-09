package frontend.SyntaxUnits;

import frontend.SyntaxUnits.Exps.AddExp;
import frontend.SyntaxUnits.VarInits.VarInitUnit;

public class Exp implements VarInitUnit {
    private final AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(addExp.toPrint());
        stringBuilder.append("<Exp>\n");
        return stringBuilder.toString();
    }
}
