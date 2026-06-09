package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//FuncType â†’ 'void' | 'int' | 'char'
public class FuncType implements SyntaxNode {
    private Token funcType;

    public FuncType(Token funcType) {
        assert funcType.isOf(TokenType.INTTK, TokenType.CHARTK, TokenType.VOIDTK);
        this.funcType = funcType;
    }

    @Override
    public void print() {
        AST.ast.addLine(funcType.toString());
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<FuncType>";
    }
}
