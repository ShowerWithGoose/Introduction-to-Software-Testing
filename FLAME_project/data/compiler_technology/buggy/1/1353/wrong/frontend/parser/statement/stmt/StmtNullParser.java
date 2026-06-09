package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

public class StmtNullParser {
    private TokenListIterator iterator;
    /* StmtNull Attributes */
    private Token semicn = null; // ';'

    public StmtNullParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtNull pasreStmtNull() {
        this.semicn = this.iterator.next();
        StmtNull stmtNull = new StmtNull(this.semicn);
        if (!this.semicn.getTokenType().equals(TokenType.SEMICN)) {
            System.out.println("EXPECT SEMICN IN STMTNULLPARSER");
            handleIError();
        }
        return stmtNull;
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
