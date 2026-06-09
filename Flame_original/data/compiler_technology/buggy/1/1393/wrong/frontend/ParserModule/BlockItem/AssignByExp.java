package frontend.ParserModule.BlockItem;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.ParserModule.exps.AddExp;
import frontend.ParserModule.exps.EqExp;
import frontend.ParserModule.exps.Lvalue;

public class AssignByExp implements BlockItem {
    private final Lvalue lVal;
    private final AddExp rExp;
    private final int errorLocate;//缺分号
    public AssignByExp(Lvalue lVal,AddExp rExp,int errorLocate){
        this.lVal = lVal;
        this.rExp = rExp;
        this.errorLocate = errorLocate;
    }

    @Override
    public void printRes() {
        lVal.printForLValue();
        System.out.println("ASSIGN =");
        rExp.printRes();
        System.out.println("<Exp>");
        System.out.println("SEMICN ;");
        System.out.println("<Stmt>");
    }

    @Override
    public void checkGrammarError() {
        lVal.checkGrammarError();
        rExp.checkGrammarError();
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'i'));
        }
    }

}
