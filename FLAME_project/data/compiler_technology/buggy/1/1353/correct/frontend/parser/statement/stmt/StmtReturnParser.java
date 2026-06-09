package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class StmtReturnParser {
    private TokenListIterator iterator;
    /* StmtPrint Attributes */
    private Token returnTk; // 'return'
    private Exp exp = null; // MAY exist
    private Token semicn; // ';'
    private StmtReturn stmtReturn = null;

    public StmtReturnParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtReturn parseStmtReturn() {
        this.returnTk = this.iterator.next();
        if (!this.returnTk.getTokenType().equals(TokenType.RETURNTK)) {
            System.out.println("EXPECT RETURNTK IN STMTRETURNPARSER");
        }
        Token token = this.iterator.next();
        if (!token.getTokenType().equals(TokenType.SEMICN)) {
            if (token.getTokenType().equals(TokenType.IDENFR) || token.getTokenType().equals(TokenType.LPARENT) || token.getTokenType().equals(TokenType.INTCON) || token.getTokenType().equals(TokenType.CHRCON) || token.getTokenType().equals(TokenType.PLUS) || token.getTokenType().equals(TokenType.MINU) || token.getTokenType().equals(TokenType.NOT)) {
                this.iterator.unRead(1);
                ExpParser expParser = new ExpParser(this.iterator);
                this.exp = expParser.parseExp();
                this.semicn = this.iterator.next();
                if (!this.semicn.getTokenType().equals(TokenType.SEMICN)) {
                    System.out.println("ERROR : EXPECT SEMICN");
                    handleIError();
                }
                stmtReturn = new StmtReturn(this.returnTk, this.exp, this.semicn);
            } else {
                System.out.println("ERROR : EXPECT SEMICN");
                handleIError();
                stmtReturn = new StmtReturn(this.returnTk, this.semicn);
            }
        } else {
            this.semicn = token;
            stmtReturn = new StmtReturn(this.returnTk, this.semicn);
        }
        return stmtReturn;
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
