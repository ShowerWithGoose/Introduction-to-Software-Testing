package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class StmtExpParser {
    private TokenListIterator iterator;
    /* StmtExp Attributes */
    private Exp exp = null;
    private Token semicn = null; // ';'

    public StmtExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtExp parseStmtExp() {
        ExpParser expParser = new ExpParser(this.iterator);
        this.exp = expParser.parseExp();
        this.semicn = this.iterator.next();
        if (!semicn.getTokenType().equals(TokenType.SEMICN)) {
            System.out.println("ERROR : EXPECT SEMICN");
            handleIError();
        }
        StmtExp stmtExp = new StmtExp(this.exp, this.semicn);
        return stmtExp;
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
