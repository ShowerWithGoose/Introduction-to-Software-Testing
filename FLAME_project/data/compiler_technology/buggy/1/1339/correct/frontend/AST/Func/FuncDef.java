package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.Stmt.Block;
import frontend.AST.SyntaxNode;
import frontend.Token;
import frontend.TokenType;

//FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block // j
public class FuncDef implements SyntaxNode {
    private FuncType funcType;
    private Token ident;
    private FuncFParams funcFParams;
    private Block body;

    public FuncDef(FuncType funcType, Token ident, FuncFParams funcFParams, Block body) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.body = body;
    }

    public FuncDef(FuncType funcType, Token ident, Block body) {
        this.funcType = funcType;
        this.ident = ident;
        this.body = body;
    }

    @Override
    public void print() {
        funcType.print();
        AST.ast.addLine(ident.toString());
        AST.ast.addLine(TokenType.LPARENT + " (");
        if (funcFParams != null) {
            funcFParams.print();
        }
        AST.ast.addLine(TokenType.RPARENT + " )");
        body.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<FuncDef>";
    }
}
