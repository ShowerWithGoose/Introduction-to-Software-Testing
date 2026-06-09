package frontend.SyntaxUnits;

import frontend.SyntaxUnits.ConstInits.ConstInitUnit;
import frontend.SyntaxUnits.Exps.ConstExp;

import java.util.ArrayList;

public class ConstInitVal implements SyntaxUnit {
    private final ConstInitUnit constInitUnit;
    public ConstInitVal(ConstInitUnit constInitUnit) {
        this.constInitUnit = constInitUnit;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(constInitUnit.toPrint());
        stringBuilder.append("<ConstInitVal>\n");
        return stringBuilder.toString();
    }
}
