package syntacticanalysis.node.expression;

public class ConstExp {
    private String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp)
    {
        this.addExp = addExp;
    }

    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
