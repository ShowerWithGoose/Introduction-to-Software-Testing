package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Exp;

public class ReturnStmt implements StmtInter {
    // 'return' [Exp]
    private final LexType returnToken;
    private final Exp returnExp;

    public ReturnStmt(LexType returnToken) {
        this.returnToken = returnToken;
        this.returnExp = null;
    }

    public ReturnStmt(LexType returnToken, Exp returnExp) {
        this.returnToken = returnToken;
        this.returnExp = returnExp;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(returnToken.toString());
        if (returnExp != null) {
            result.append(returnExp);
        }
        return result.toString();
    }
}
