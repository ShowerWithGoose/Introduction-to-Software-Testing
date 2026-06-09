package frontend.Parser.SyntaxNode.InitVal;

import frontend.Parser.SyntaxNode.Exp;

public class InitValExp extends InitVal {
    private Exp exp;

    public InitValExp(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return exp.toString() + name + "\n";
    }
}
