package frontend.SyntaxUnits;

import frontend.SyntaxUnits.VarInits.VarInitUnit;

import java.util.ArrayList;

public class InitVal implements SyntaxUnit {
    private final VarInitUnit varInitUnit;

    public InitVal(VarInitUnit varInitUnit) {
        this.varInitUnit = varInitUnit;
    }


    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(varInitUnit.toPrint());
        stringBuilder.append("<InitVal>\n");
        return stringBuilder.toString();
    }
}
