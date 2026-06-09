package parser.vardecl;

import parser.constdecl.ConstExp;

public class VarDef {
    private final String ident;
    private ConstExp constExp;
    private InitVal initVal;

    public VarDef(String ident) {
        this.ident = ident;
        this.constExp = null;
        this.initVal = null;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }

    public String toString() {
        StringBuilder str = new StringBuilder("IDENFR " + this.ident + "\n");
        if (this.constExp != null) {
            str.append("LBRACK [\n");
            str.append(this.constExp.toString());
            str.append("RBRACK ]\n");
        }
        if (this.initVal != null) {
            str.append("ASSIGN =\n");
            str.append(this.initVal.toString());
        }
        str.append("<VarDef>\n");
        return str.toString();
    }
}
