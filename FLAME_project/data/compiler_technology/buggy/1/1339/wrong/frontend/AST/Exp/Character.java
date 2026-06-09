package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;

//Character â†’ CharConst
public class Character implements SyntaxNode {
    private Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public void print() {
        AST.ast.addLine(charConst.toString());
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Character>";
    }
}
