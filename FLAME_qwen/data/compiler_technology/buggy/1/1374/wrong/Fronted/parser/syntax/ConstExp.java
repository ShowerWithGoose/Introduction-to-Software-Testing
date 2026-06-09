package Fronted.parser.syntax;

// ConstExp â†’ AddExp
public class ConstExp {

    private static final String name = "<ConstExp>";

    private AddExp addExp = null;

    public ConstExp(AddExp addExp) {
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
