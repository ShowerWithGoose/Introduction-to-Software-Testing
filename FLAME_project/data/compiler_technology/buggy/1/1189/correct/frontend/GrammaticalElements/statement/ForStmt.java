package frontend.GrammaticalElements.statement;

import frontend.GrammaticalElements.expression.Exp;
import frontend.GrammaticalElements.expression.LVal;
import frontend.Token;

public class ForStmt {
    /*const string name = "<ForStmt>";
    LVal* lVal;
    Token assign;
    Exp* exp;*/
    private final String name = "<ForStmt>";
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Exp exp, Token assign) {
        this.lVal = lVal;
        this.exp = exp;
        this.assign = assign;
    }

    @Override
    public String toString() {
        return lVal.toString() +
                assign.toString() +
                exp.toString() +
                this.name + '\n';
    }
}
