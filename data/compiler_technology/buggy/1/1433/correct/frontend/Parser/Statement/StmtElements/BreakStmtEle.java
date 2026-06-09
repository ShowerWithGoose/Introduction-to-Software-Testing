package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Statement.StmtEle;

public class BreakStmtEle implements StmtEle {
    private Token breakToken;
    private Token semicnToken;

    public BreakStmtEle(Token breakToken, Token semicnToken) {
        this.breakToken = breakToken;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(breakToken);
        sb.append(semicnToken);
        return sb.toString();
    }
    
}
