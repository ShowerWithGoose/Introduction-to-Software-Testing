package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.Exp.ConstExp;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

// VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
public class VarDef implements SyntaxNode {
    private Token ident;
    private ConstExp constExp;
    private InitVal initVal;

    public VarDef(Token ident) {
        this.ident = ident;
    }

    public VarDef(Token ident, ConstExp constExp) {
        this.ident = ident;
        this.constExp = constExp;
    }

    public VarDef(Token ident, InitVal initVal) {
        this.ident = ident;
        this.initVal = initVal;
    }

    public VarDef(Token ident, ConstExp constExp, InitVal initVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.initVal = initVal;
    }

    @Override
    public void print() {
        AST.ast.addLine(ident.toString());
        if (constExp != null) {
            AST.ast.addLine(TokenType.LBRACK + " [");
            constExp.print();
            AST.ast.addLine(TokenType.RBRACK + " ]");
        }
        if (initVal != null) {
            AST.ast.addLine(TokenType.ASSIGN + " =");
            initVal.print();
        }
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<VarDef>";
    }
}
