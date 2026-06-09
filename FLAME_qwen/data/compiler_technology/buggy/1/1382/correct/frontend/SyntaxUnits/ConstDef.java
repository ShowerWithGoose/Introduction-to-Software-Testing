package frontend.SyntaxUnits;

import frontend.SyntaxUnits.Exps.ConstExp;
import frontend.Token;

public class ConstDef implements SyntaxUnit{
    private final Token ident;
    private final boolean isArray;
    private final ConstExp constExp;
    private final ConstInitVal constInitVal;

    public ConstDef(Token ident, ConstInitVal constInitVal) {
        this.constExp = null;
        this.ident = ident;
        this.isArray = false;
        this.constInitVal = constInitVal;
    }

    public ConstDef(Token ident, ConstExp constExp, ConstInitVal constInitVal) {
        this.constExp = constExp;
        this.ident = ident;
        this.isArray = true;
        this.constInitVal = constInitVal;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ident.toPrint());
        if (constExp != null) {
            stringBuilder.append("LBRACK" + " [" +  "\n");
            stringBuilder.append(constExp.toPrint());
            stringBuilder.append("RBRACK" + " ]" +  "\n");
        }
        stringBuilder.append("ASSIGN" + " =" +  "\n");
        stringBuilder.append(constInitVal.toPrint());
        stringBuilder.append("<ConstDef>\n");
        return stringBuilder.toString();
    }
}
