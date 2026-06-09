package frontend.Parser.Stmt;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class StmtContinueParser {
    private TokenListReader reader;
    private Token continueTk;
    private Token semicn;

    public StmtContinueParser(TokenListReader reader) {
        this.reader = reader;
    }

    public StmtContinue parseStmtContinue() {
        this.continueTk = this.reader.getnextToken();
        if (!this.continueTk.getType().equals(TokenType.BREAKTK)) {
            System.out.println("error:stmtcontinue");
        }
        this.semicn = this.reader.getnextToken();
        if(!this.semicn.getType().equals(TokenType.SEMICN))
        {
            // error!
            ErrorHandler.getInstance().reportError(this.reader.getPreviousToken().getLine(),"i");
            this.reader.backward(1);
        }
        StmtContinue stmtContinue = new StmtContinue(this.continueTk, this.semicn);
        return stmtContinue;
    }
}
