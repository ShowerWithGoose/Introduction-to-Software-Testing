package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Statement.StmtEle;

public class ContinueStmtEle implements StmtEle {
    private Token continueToken;
    private Token semicnToken;

    public ContinueStmtEle(Token continueToken, Token semicnToken) {
        this.continueToken = continueToken;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(continueToken);
        sb.append(semicnToken);
        return sb.toString();
    }
    
}
