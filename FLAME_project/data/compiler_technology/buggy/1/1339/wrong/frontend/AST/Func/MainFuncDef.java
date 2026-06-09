package frontend.AST.Func;

import frontend.AST.AST;
import frontend.AST.Stmt.Block;
import frontend.AST.SyntaxNode;
import frontend.TokenType;

//MainFuncDef â†’ 'int' 'main' '(' ')' Block // j
public class MainFuncDef implements SyntaxNode {

    private Block body;

    public MainFuncDef(Block body) {
        this.body = body;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.INTTK + " int");
        AST.ast.addLine(TokenType.MAINTK + " main");
        AST.ast.addLine(TokenType.LPARENT + " (");
        AST.ast.addLine(TokenType.RPARENT + " )");
        body.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<MainFuncDef>";
    }
}
