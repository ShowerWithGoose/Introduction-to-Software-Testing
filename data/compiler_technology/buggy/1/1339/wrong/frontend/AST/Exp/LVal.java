package frontend.AST.Exp;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//LVal â†’ Ident ['[' Exp ']'] // k
public class LVal implements SyntaxNode {
    private Token ident;
    private Exp exp;

    public LVal(Token ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }

    public LVal(Token ident) {
        this.ident = ident;
    }

    @Override
    public void print() {
        AST.ast.addLine(ident.toString());
        if (exp != null) {
            AST.ast.addLine(TokenType.LBRACK + " [");
            exp.print();
            AST.ast.addLine(TokenType.RBRACK + " ]");
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<LVal>";
    }
}
