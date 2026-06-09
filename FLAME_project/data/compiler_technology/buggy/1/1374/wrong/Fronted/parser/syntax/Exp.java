package Fronted.parser.syntax;

//  Exp â†’ AddExp
public class Exp {

    private static final String name = "<Exp>";

    private AddExp addExp = null;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(addExp);
        out.append(name).append("\n");
        return out.toString();
    }

    public AddExp getAddExp() {
        return addExp;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }
}

