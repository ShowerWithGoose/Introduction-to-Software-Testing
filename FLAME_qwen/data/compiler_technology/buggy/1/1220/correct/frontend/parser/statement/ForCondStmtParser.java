package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

public class ForCondStmtParser {
    private TokenIterator iterator;
    private Token forTk;
    private Token leftParent;
    private ForStmt forStmt1;
    private Token semicn1;
    private Cond cond;
    private Token semicn2;
    private ForStmt forStmt2;
    private  Token rightParent;
    private Stmt stmt;
    //不会发生缺少分号的错误

    public ForCondStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ForCondStmt parseForCondStmt() {
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        forTk = iterator.getNextToken();
        leftParent = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.SEMICN) {
            forStmt1 = null;
            semicn1 = t1;
        } else {
            iterator.ungetToken(1);
            ForStmtParser parser = new ForStmtParser(iterator);
            forStmt1 = parser.parseForStmt();
            semicn1 = iterator.getNextToken();
        }
        Token t2 = iterator.getNextToken();
        if (t2.getType() == TokenType.SEMICN) {
            forStmt2 = null;
            semicn2 = t2;
        } else {
            iterator.ungetToken(1);
            CondParser parser = new CondParser(iterator);
            cond = parser.parseCond();
            semicn2 = iterator.getNextToken();
        }
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        Token t3 = iterator.getNextToken();
        if (t3.getType() == TokenType.RPARENT) {
            forStmt2 = null;
            rightParent = t3;
        } else {
            iterator.ungetToken(1);
            ForStmtParser parser = new ForStmtParser(iterator);
            forStmt2 = parser.parseForStmt();
            rightParent = iterator.getNextToken();
        }
        StmtParser stmtParser = new StmtParser(iterator);
        stmt = stmtParser.parseStmt();
        return new ForCondStmt(forTk, leftParent, forStmt1, semicn1, cond, semicn2, forStmt2, rightParent, stmt);
    }
}
