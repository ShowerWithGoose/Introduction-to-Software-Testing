package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;

//Exp â†’ AddExp
public class Exp implements SyntaxNode {
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public void print() {
        addExp.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Exp>";
    }
}
