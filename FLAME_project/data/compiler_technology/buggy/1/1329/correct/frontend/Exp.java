package frontend;

public class Exp {
    // AddExp
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setWordWrong(int type) {
        addExp.setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append("<Exp>");
        sb.append("\n");
        return sb.toString();
    }
}
