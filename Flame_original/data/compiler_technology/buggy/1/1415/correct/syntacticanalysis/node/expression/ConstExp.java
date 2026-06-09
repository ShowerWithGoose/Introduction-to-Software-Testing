package syntacticanalysis.node.expression;

public class ConstExp {
    private String name = "<ConstExp>";
    private final AddExp addExp;

    public ConstExp(AddExp addExp)
    {
        this.addExp = addExp;
    }

    public String syntaxOutput()
    {
        return addExp.syntaxOutput() + "\n" + name;
    }
}
