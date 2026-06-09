package frontend.GrammaticalElements.expression;

public class ConstExp {
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
