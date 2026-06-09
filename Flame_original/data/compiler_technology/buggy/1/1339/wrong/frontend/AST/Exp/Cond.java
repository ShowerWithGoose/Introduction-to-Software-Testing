package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;

//Cond â†’ LOrExp
public class Cond implements SyntaxNode {
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public void print() {
        lOrExp.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Cond>";
    }
}
