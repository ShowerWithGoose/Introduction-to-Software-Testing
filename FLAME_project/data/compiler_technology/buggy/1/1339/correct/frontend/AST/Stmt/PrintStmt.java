package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.Exp.Exp;
import frontend.Token;
import frontend.TokenType;

import java.util.ArrayList;

//'printf''('StringConst {','Exp}')'';' // i j
public class PrintStmt extends Stmt{
    private Token stringConst;
    private ArrayList<Exp> exps;
    public PrintStmt(Token stringConst, ArrayList<Exp> exps) {
        this.stringConst = stringConst;
        this.exps = exps;
    }

    @Override
    public void print() {
        AST.ast.addLine(TokenType.PRINTFTK + " printf");
        AST.ast.addLine(TokenType.LPARENT + " (");
        AST.ast.addLine(stringConst.toString());
        for (Exp exp : exps) {
            AST.ast.addLine(TokenType.COMMA + " ,");
            exp.print();
        }
        AST.ast.addLine(TokenType.RPARENT + " )");
        AST.ast.addLine(TokenType.SEMICN + " ;");
        super.print();
    }
}
