package parser.exp;

public class LVal implements PrimaryExpForm {
    private final String ident;
    private final Exp exp;

    public LVal(String ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }

    public String toString() {
        if (this.exp == null) {
            return "IDENFR " + this.ident + "\n<LVal>\n";
        }
        String ide = "IDENFR " + this.ident + "\nLBRACK [\n";
        return ide + this.exp + "RBRACK ]\n<LVal>\n";
    }
}
