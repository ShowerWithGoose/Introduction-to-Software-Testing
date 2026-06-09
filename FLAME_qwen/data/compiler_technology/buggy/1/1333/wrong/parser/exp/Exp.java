package parser.exp;

public class Exp implements PrimaryExpForm {
    private final AddExp addExp;
    private final boolean hasParent;

    public Exp(AddExp addExp, boolean hasParent) {
        this.addExp = addExp;
        this.hasParent = hasParent;
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        if (this.hasParent) {
            str.append("LPARENT (\n");
        }
        str.append(this.addExp.toString());
        str.append("<Exp>\n");
        if (this.hasParent) {
            str.append("RPARENT )\n");
        }
        return str.toString();
    }
}
