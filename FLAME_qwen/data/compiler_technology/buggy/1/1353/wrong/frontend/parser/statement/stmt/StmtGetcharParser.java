package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

public class StmtGetcharParser {
    private TokenListIterator iterator;
    /* StmtGetchar Attributes */
    private LVal lval = null;
    private Token eq = null; // '='
    private Token getchar = null; // 'getchar'
    private Token leftParent = null; // '('
    private Token rightParent = null; // ')'
    private Token semicn = null; // ';'

    public StmtGetcharParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtGetint parseStmtGetChar() {
        LValParser lvalParser = new LValParser(this.iterator);
        this.lval = lvalParser.parseLVal();
        this.eq = this.iterator.next();
        this.getchar = this.iterator.next();
        this.leftParent = this.iterator.next();
        this.rightParent = this.iterator.next();
        if (!rightParent.getTokenType().equals(TokenType.RPARENT)){
            System.out.println("ERROR : EXPECT RPARENT");
            handleJError();
        }
        this.semicn = this.iterator.next();
        if (!semicn.getTokenType().equals(TokenType.SEMICN)) {
            System.out.println("ERROR : EXPECT SEMICN");
            handleIError();
        }
        StmtGetint stmtGetint = new StmtGetint(this.lval, this.eq, this.getchar,
                this.leftParent, this.rightParent, this.semicn);
        return stmtGetint;
    }

    /**
     * i error
     * missing ';'
     */
    private void handleIError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new frontend.error.Error(ErrorType.MISSING_SEMICN, iterator.next().getLine()));
        this.semicn = null;
    }

    /**
     * j error
     * missing ')'
     */
    private void handleJError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RPARENT, iterator.next().getLine()));
        this.rightParent = null;
    }
}
