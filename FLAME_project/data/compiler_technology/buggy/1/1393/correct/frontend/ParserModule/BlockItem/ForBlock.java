package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.ParserModule.exps.LOrExp;

public class ForBlock implements BlockItem{
    private ForStmt forStmt1;
    private LOrExp cond;
    private ForStmt forStmt2;
    private BlockItem body;
    private int errorLocate;
    public ForBlock(ForStmt forStmt1,LOrExp cond,ForStmt forStmt2,BlockItem body,int errorLocate){
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.body = body;
        this.errorLocate = errorLocate;
    }

    @Override
    public void printRes() {
        System.out.println("FORTK for");
        System.out.println("LPARENT (");
        if(forStmt1!=null){
            forStmt1.printRes();
        }
        System.out.println("SEMICN ;");
        if(cond!=null){
            cond.printRes();
            System.out.println("<Cond>");
        }
        System.out.println("SEMICN ;");
        if(forStmt2!=null){
            forStmt2.printRes();
        }
        System.out.println("RPARENT )");
        body.printRes();
        System.out.println("<Stmt>");
    }
    

    @Override
    public void checkGrammarError() {
        if(forStmt1!=null){
            forStmt1.checkGrammarError();
        }
        if(cond!=null){
            cond.checkGrammarError();
        }
        if(forStmt2!=null){
            forStmt2.checkGrammarError();
        }
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'j'));
        }
        body.checkGrammarError();
    }
}
