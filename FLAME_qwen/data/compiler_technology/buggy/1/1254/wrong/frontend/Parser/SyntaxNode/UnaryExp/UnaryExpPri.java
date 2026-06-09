package frontend.Parser.SyntaxNode.UnaryExp;

import frontend.Parser.SyntaxNode.PrimaryExp.PrimaryExp;

public class UnaryExpPri extends UnaryExp {
    private PrimaryExp primaryExp;

    public UnaryExpPri(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    @Override
    public String toString() {
        return primaryExp.toString() + name + "\n";
    }
}
