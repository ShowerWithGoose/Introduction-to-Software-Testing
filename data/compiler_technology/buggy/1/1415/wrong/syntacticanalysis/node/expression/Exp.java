package syntacticanalysis.node.expression;

public class Exp {
    private String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String syntaxOutput() {
        return addExp.syntaxOutput() + "\n" + name;
    }
}
