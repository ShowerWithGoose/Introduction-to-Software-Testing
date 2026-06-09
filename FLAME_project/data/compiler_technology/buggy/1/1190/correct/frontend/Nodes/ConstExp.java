package frontend.Nodes;

public class ConstExp implements Node {
    private AddExp addExp;

    public ConstExp() {
        this.addExp = null;
    }

    public void addAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String error() {
        return addExp.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append("<ConstExp>\n");
        return sb.toString();
    }
}
