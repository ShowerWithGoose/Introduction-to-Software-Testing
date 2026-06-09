package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.LVal;
import frontend.Token;
import frontend.TokenType;

//LVal '=' 'getint''('')'';' // i j
//LVal '=' 'getchar''('')'';' // i j
public class GetStmt extends Stmt{
    private LVal lVal;
    private Token getFunc;
    public GetStmt(LVal lVal, Token getFunc) {
        this.lVal = lVal;
        this.getFunc = getFunc;
    }

    @Override
    public void print() {
        lVal.print();
        AST.ast.addLine(TokenType.ASSIGN + " =");
        AST.ast.addLine(getFunc.toString());
        AST.ast.addLine(TokenType.LPARENT + " (");
        AST.ast.addLine(TokenType.RPARENT + " )");
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
