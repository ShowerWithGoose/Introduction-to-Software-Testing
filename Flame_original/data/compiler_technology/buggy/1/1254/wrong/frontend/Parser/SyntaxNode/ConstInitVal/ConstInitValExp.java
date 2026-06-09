package frontend.Parser.SyntaxNode.ConstInitVal;

import frontend.Parser.SyntaxNode.ConstExp;

public class ConstInitValExp extends ConstInitVal {
    private ConstExp constExp;

    public ConstInitValExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    @Override
    public String toString() {
        return constExp.toString() + name + "\n";
    }
}
