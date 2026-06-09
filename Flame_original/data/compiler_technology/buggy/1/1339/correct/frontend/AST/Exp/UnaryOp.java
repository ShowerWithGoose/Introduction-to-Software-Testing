package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
public class UnaryOp implements SyntaxNode {
    private Token unaryOp;

    public UnaryOp(Token unaryOp) {
        assert unaryOp.isOf(TokenType.PLUS, TokenType.MINU, TokenType.NOT);
        this.unaryOp = unaryOp;
    }

    @Override
    public void print() {
        AST.ast.addLine(unaryOp.toString());
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<UnaryOp>";
    }
}
