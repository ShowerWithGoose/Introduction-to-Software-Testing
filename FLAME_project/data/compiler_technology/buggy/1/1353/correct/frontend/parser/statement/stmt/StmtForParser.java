package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;
import frontend.parser.statement.ForStmt;
import frontend.parser.statement.ForStmtParser;

public class StmtForParser {
    private TokenListIterator iterator;
    /* StmtFor Attributes */
    private Token forTk; // 'while'
    private Token leftParent; // '('
    private ForStmt forStmt1 = null;   // MAY exist
    private Token semicn1;
    private Cond cond = null;   // MAY exist
    private Token semicn2;
    private ForStmt forStmt2 = null;   // MAY exist
    private Token rightParent; // ')'
    private Stmt stmt;

    public StmtForParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtFor parseStmtFor() {
        forTk = iterator.next();
        leftParent = iterator.next();
        semicn1 = iterator.next();
        if (!semicn1.getTokenType().equals(TokenType.SEMICN)) {
            iterator.unRead(1);
            ForStmtParser forStmtParser = new ForStmtParser(iterator);
            forStmt1 = forStmtParser.parseForStmt();
            semicn1 = iterator.next();
        }
        semicn2 = iterator.next();
        if (!semicn2.getTokenType().equals(TokenType.SEMICN)) {
            iterator.unRead(1);
            CondParser condParser = new CondParser(iterator);
            cond = condParser.parseCond();
            semicn2 = iterator.next();
        }
        rightParent = iterator.next();
        if (!rightParent.getTokenType().equals(TokenType.RPARENT)) {
            iterator.unRead(1);
            ForStmtParser forStmtParser = new ForStmtParser(iterator);
            this.forStmt2 = forStmtParser.parseForStmt();
            rightParent = iterator.next();
        }
        StmtParser stmtParser = new StmtParser(iterator);
        stmt = stmtParser.parseStmt();

        StmtFor stmtFor = new StmtFor(this.forTk, this.leftParent, this.forStmt1, this.semicn1, this.cond, this.semicn2, this.forStmt2, this.rightParent, this.stmt);

        return stmtFor;
    }
}
