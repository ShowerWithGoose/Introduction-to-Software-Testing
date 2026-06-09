package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class StmtBreakParser {
    private TokenListReader reader;
    private Token breakTk;
    private Token semicn;


    public StmtBreakParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtBreak parseStmtBreak() {
        this.breakTk = this.reader.getnextToken();
        if (!this.breakTk.getType().equals(TokenType.BREAKTK)) {
            System.out.println("error:stmtbreak");
        }
        this.semicn = this.reader.getnextToken();
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        StmtBreak stmtBreak = new StmtBreak(this.breakTk, this.semicn);
        return stmtBreak;
    }
}
