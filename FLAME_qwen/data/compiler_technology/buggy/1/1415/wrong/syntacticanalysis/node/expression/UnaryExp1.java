package syntacticanalysis.node.expression;

public class UnaryExp1 extends UnaryExp {
    private String name = "<UnaryExp>";
    private PrimaryExp primaryExp;

    public UnaryExp1(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    @Override
    public String syntaxOutput() {
        return primaryExp.syntaxOutput() + "\n" + name;
    }
}
