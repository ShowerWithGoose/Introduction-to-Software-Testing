package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.ParserModule.exps.AddExp;

public class SingleExp implements BlockItem{
    private AddExp exp;
    private int errorLocate;//缺分号
    public SingleExp(AddExp exp,int errorLocate){
        this.exp = exp;
        this.errorLocate = errorLocate;
    }

    @Override
    public void printRes() {
        if(exp!=null){
            exp.printRes();
            System.out.println("<Exp>");
        }
        System.out.println("SEMICN ;");
        System.out.println("<Stmt>");
    }
    @Override
    public void checkGrammarError() {
        if(exp!=null){
            exp.checkGrammarError();
        }
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'i'));
        }
    }
}
