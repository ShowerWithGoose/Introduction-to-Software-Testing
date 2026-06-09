package frontend;

public class Cond {
    // LOrExp
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void setWordWrong(int type) {
        lOrExp.setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.toString());
        sb.append("<Cond>");
        sb.append("\n");
        return sb.toString();
    }
}
