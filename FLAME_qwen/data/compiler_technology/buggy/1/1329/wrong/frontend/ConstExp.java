package frontend;

public class ConstExp {
    // AddExp,使用的 Ident 必须是常量
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setWordWrong(int type) {
        addExp.setWordWrong(type);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append("<ConstExp>");
        sb.append("\n");
        return sb.toString();
    }
}
