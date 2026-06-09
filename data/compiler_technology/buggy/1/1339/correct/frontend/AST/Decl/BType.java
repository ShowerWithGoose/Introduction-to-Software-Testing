package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

// BType → 'int' | 'char'
public class BType implements SyntaxNode {
    private final Token token;

    public BType(Token token) {
        assert token.isOf(TokenType.INTTK, TokenType.CHARTK);
        this.token = token;
    }

    @Override
    public void print() {
        AST.ast.addLine(token.toString());
    }

    @Override
    public String getName() {
        // 不需要打印
        return "<BType>";
    }
}
