package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

public class StmtCondParser {
    private TokenListIterator iterator;
    /* StmtCond Attributes */
    private Token ifTK = null; // 'if'
    private Token leftParent = null; // '('
    private Cond cond = null;
    private Token rightParent = null; // ')'
    private Stmt ifStmt = null;
    private Token elseTk = null; // MAY exist 'else'
    private Stmt elseStmt = null; // MAY exist else statement
    private StmtCond stmtCond = null;

    public StmtCondParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtCond parseStmtCond() {
        this.ifTK = this.iterator.next();
        if (!this.ifTK.getTokenType().equals(TokenType.IFTK)) {
            System.out.println("EXPECT IFTK IN STMTCONDPARSER");
        }
        this.leftParent = this.iterator.next();
        if (!this.leftParent.getTokenType().equals(TokenType.LPARENT)) {
            System.out.println("EXPECT LEFTPARENT IN STMTCONDPARSER");
        }
        CondParser condParser = new CondParser(this.iterator);
        this.cond = condParser.parseCond();
        this.rightParent = this.iterator.next();
        if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
            System.out.println("EXPECT RPARENT IN STMTCONDPARSER");
            handleJError();
        }
        StmtParser stmtParser = new StmtParser(this.iterator);
        this.ifStmt = stmtParser.parseStmt();
        this.elseTk = this.iterator.next();
        if (this.elseTk.getTokenType().equals(TokenType.ELSETK)) {
            this.elseStmt = stmtParser.parseStmt();
            this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                    this.cond, this.rightParent, this.ifStmt, this.elseTk, this.elseStmt);
        } else {
            this.iterator.unRead(1);
            this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                    this.cond, this.rightParent, this.ifStmt);
        }
        return this.stmtCond;
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
