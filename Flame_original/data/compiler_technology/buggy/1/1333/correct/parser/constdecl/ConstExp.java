package parser.constdecl;

import parser.exp.AddExp;

public class ConstExp {
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String toString() {
        return this.addExp.toString() + "<ConstExp>\n";
    }
}
