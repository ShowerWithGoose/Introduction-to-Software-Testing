package frontend.AST.Decl;

import frontend.AST.AST;
import frontend.AST.Exp.ConstExp;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
public class ConstDef implements SyntaxNode {
    private Token ident;
    private ConstExp constExp;
    private ConstInitVal constInitVal;
    public ConstDef(Token Ident, ConstExp constExp, ConstInitVal constInitVal){
        this.ident = Ident;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
    }

    public ConstDef(Token Ident, ConstInitVal constInitVal){
        this.ident = Ident;
        this.constInitVal = constInitVal;
    }

    @Override
    public void print() {
        AST.ast.addLine(ident.toString());
        if(constExp != null){
            AST.ast.addLine(TokenType.LBRACK + " [");
            constExp.print();
            AST.ast.addLine(TokenType.RBRACK + " ]");
        }
        AST.ast.addLine(TokenType.ASSIGN + " =");
        constInitVal.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<ConstDef>";
    }
}
