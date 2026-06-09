package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.Decl.BType;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//FuncFParam â†’ BType Ident ['[' ']'] // k
public class FuncFParam implements SyntaxNode {
    private BType btype;
    private Token ident;
    private boolean isArray;

    public FuncFParam(BType btype, Token ident, boolean isArray) {
        this.btype = btype;
        this.ident = ident;
        this.isArray = isArray;
    }

    @Override
    public void print() {
        btype.print();
        AST.ast.addLine(ident.toString());
        if (isArray){
            AST.ast.addLine(TokenType.LBRACK + " [");
            AST.ast.addLine(TokenType.RBRACK + " ]");
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<FuncFParam>";
    }
}
