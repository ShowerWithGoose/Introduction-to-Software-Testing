package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.ParserModule.exps.LOrExp;

public class IfBlock implements BlockItem{
    private LOrExp cond;
    private BlockItem ifStmt;
    private BlockItem elseStmt;
    private int errorLocate;//缺小括号
    public IfBlock(LOrExp cond,BlockItem ifStmt,BlockItem elseStmt,int errorLocate){
        this.cond = cond;
        this.ifStmt = ifStmt;
        this.elseStmt = elseStmt;
        this.errorLocate = errorLocate;
    }

    @Override
    public void printRes() {
        System.out.println("IFTK if");
        System.out.println("LPARENT (");
        cond.printRes();
        System.out.println("<Cond>");
        System.out.println("RPARENT )");
        ifStmt.printRes();
        if(elseStmt!=null){
            System.out.println("ELSETK else");
            elseStmt.printRes();
        }
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        cond.checkGrammarError();
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'j'));
        }
        ifStmt.checkGrammarError();
        if(elseStmt!=null){
            elseStmt.checkGrammarError();
        }
    }
}
