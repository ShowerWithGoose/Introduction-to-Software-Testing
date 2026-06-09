package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;

public class bcStmt implements StmtInter {
    // 'break' | 'continue'
    private final LexType bcToken;

    public bcStmt(LexType bcToken) {
        this.bcToken = bcToken;
    }

    @Override
    public String toString() {
        return bcToken.toString();
    }
}
