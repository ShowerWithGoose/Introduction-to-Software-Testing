package frontend.Nodes;

public class Cond implements Node {
    private LOrExp lOrExp;

    public Cond() {
        this.lOrExp = null;
    }

    public void addLOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String error() {
        if (lOrExp == null) {
            return "";
        }
        return lOrExp.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (lOrExp != null) {
            sb.append(lOrExp.toString());
        }
        sb.append("<Cond>\n");
        return sb.toString();
    }
}
