package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

//Number â†’ IntConst
public class Number implements SyntaxNode {
    private Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public void print() {
        AST.ast.addLine(intConst.toString());
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Number>";
    }
}
