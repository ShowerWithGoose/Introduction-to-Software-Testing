package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

public class StmtContinueParser {
    private TokenListIterator iterator;
    /* StmtContinue Attributes */
    private Token continueTk; // 'continue'
    private Token semicn; // ';'

    public StmtContinueParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtContinue parseStmtContinue() {
        this.continueTk = this.iterator.next();
        if (!this.continueTk.getTokenType().equals(TokenType.CONTINUETK)) {
            System.out.println("EXPECT CONTINUETK IN STMTCONTINUEPARSER");
        }
        this.semicn = this.iterator.next();
        if (!this.semicn.getTokenType().equals(TokenType.SEMICN)) {
            System.out.println("EXPECT SEMICN IN STMTCONTINUEPARSER");
            handleIError();
        }
        StmtContinue stmtContinue = new StmtContinue(this.continueTk, this.semicn);
        return stmtContinue;
    }

    /**
     * i error
     * missing ';'
     */
    private void handleIError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_SEMICN, iterator.next().getLine()));
        this.semicn = null;
    }
}
