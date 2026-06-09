package parser.constdecl;

public class ConstDef {
    private final String ident;
    private final ConstExp constExp;
    private final ConstInitVal constInitVal;

    public ConstDef(String ident, ConstExp constExp, ConstInitVal constInitVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
    }

    public String toString() {
        StringBuilder str = new StringBuilder("IDENFR " + this.ident + "\n");
        if (this.constExp != null) {
            str.append("LBRACK [\n");
            str.append(this.constExp.toString());
            str.append("RBRACK ]\n");
        }
        str.append("ASSIGN =\n");
        str.append(this.constInitVal.toString());
        str.append("<ConstDef>\n");
        return str.toString();
    }
}
