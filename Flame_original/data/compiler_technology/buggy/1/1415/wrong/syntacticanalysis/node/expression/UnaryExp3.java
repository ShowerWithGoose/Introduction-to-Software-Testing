package syntacticanalysis.node.expression;

import syntacticanalysis.node.singal.UnaryOp;

public class UnaryExp3 extends UnaryExp {
    private String name = "<UnaryExp>";
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp3(UnaryOp unaryOp, UnaryExp unaryExp)
    {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String syntaxOutput() {
        return unaryOp.syntaxOutput() + "\n" + unaryExp.syntaxOutput() + "\n" + name;
    }
}
