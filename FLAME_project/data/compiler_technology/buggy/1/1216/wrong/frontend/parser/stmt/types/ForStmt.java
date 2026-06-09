package frontend.parser.stmt.types;

import frontend.lexer.Token;
import frontend.parser.expr.types.Exp;
import frontend.parser.expr.types.LVal;

//ForStmt â†’ LVal '=' Exp
public class ForStmt {
    private final LVal lVal;
    private final Token assign;
    private final Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    @Override
    public String toString() {
        return lVal.toString() + assign + exp + "<ForStmt>\n";
    }
}
