package syntax;

import lexer.LexType;
import logger.Logger;

public class ForStmt {
    public static final LexType[] FIRST = LVal.FIRST;

    private final LVal lVal;
    private final Exp exp;

    public ForStmt(LVal lVal, Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
        Logger.logGood("<ForStmt>\n");
    }
}
