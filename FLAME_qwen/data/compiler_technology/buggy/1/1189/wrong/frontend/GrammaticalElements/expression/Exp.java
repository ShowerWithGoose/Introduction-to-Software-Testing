package frontend.GrammaticalElements.expression;

public class Exp {
    private final String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        return addExp.toString() + this.name + '\n';
    }
}
