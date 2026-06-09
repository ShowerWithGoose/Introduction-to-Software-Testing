package frontend.SyntaxUnits;

import frontend.SyntaxUnits.Exps.ConstExp;
import frontend.Token;

public class VarDef implements SyntaxUnit{
    private final Token ident;
    private final boolean isArray;
    private final boolean isAssigned;
    private final ConstExp constExp;
    private final InitVal initVal;

    public VarDef(Token ident, InitVal initVal) {
        this.constExp = null;
        this.ident = ident;
        this.isArray = false;
        this.isAssigned = true;
        this.initVal = initVal;
    }

    public VarDef(Token ident, ConstExp constExp, InitVal initVal) {
        this.constExp = constExp;
        this.ident = ident;
        this.isArray = true;
        this.isAssigned = true;
        this.initVal = initVal;
    }

    public VarDef(Token ident) {
        this.constExp = null;
        this.ident = ident;
        this.isArray = false;
        this.isAssigned = false;
        this.initVal = null;
    }

    public VarDef(Token ident, ConstExp constExp) {
        this.constExp = constExp;
        this.ident = ident;
        this.isArray = true;
        this.isAssigned = false;
        this.initVal = null;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ident.toPrint());
        if (isArray)  {
            stringBuilder.append("LBRACK" + " [" +  "\n");
            stringBuilder.append(constExp.toPrint());
            stringBuilder.append("RBRACK" + " ]" + "\n");
        }
        if (isAssigned) {
            stringBuilder.append("ASSIGN" + " =" + "\n");
            stringBuilder.append(initVal.toPrint());
        }
        stringBuilder.append("<VarDef>\n");
        return stringBuilder.toString();
    }
}
