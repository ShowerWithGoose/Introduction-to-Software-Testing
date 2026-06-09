package frontend.ParserModule.BlockItem;

import frontend.ParserModule.exps.AddExp;
import frontend.ParserModule.exps.Lvalue;

public class ForStmt implements BlockItem{
    private Lvalue lVal;
    private AddExp rExp;

    public ForStmt(Lvalue lVal,AddExp rExp){
        this.lVal = lVal;
        this.rExp = rExp;
    }
    @Override
    public void printRes() {
        lVal.printForLValue();
        System.out.println("ASSIGN =");
        rExp.printRes();
        System.out.println("<Exp>");
        System.out.println("<ForStmt>");
    }
    @Override
    public void checkGrammarError() {
        lVal.checkGrammarError();
        rExp.checkGrammarError();
    }
}
