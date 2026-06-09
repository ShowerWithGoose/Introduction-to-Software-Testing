package frontend.Nodes;

public class Exp implements Node {
    private AddExp addExp;

    public Exp() {
        this.addExp = null;
    }

    public void addAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    @Override
    public String error() {
        if (addExp == null) {
            return "";
        }
        return addExp.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (addExp != null) {
            sb.append(addExp.toString());
        }
        sb.append("<Exp>\n");
        return sb.toString();
    }
}
