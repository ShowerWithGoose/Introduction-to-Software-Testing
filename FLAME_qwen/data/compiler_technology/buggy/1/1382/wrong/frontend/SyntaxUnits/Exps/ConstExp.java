package frontend.SyntaxUnits.Exps;
import frontend.SyntaxUnits.ConstInits.ConstInitUnit;
import frontend.SyntaxUnits.SyntaxUnit;

public class ConstExp implements ConstInitUnit {
    private final AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String toPrint() {
        return addExp.toPrint() + "<ConstExp>\n";
    }
}
