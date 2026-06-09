package frontend.Parser.SyntaxNode.UnaryExp;

import frontend.Parser.SyntaxNode.UnaryOp;

public class UnaryExpOp extends UnaryExp {
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String toString() {
        return unaryOp.toString() + unaryExp.toString() + name + "\n";
    }
}
