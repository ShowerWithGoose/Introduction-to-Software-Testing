package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

public class IfElseStmtParser {
    //j-error
    private TokenIterator iterator;
    private Token ifTk;
    private Token leftParent;
    private Cond cond;
    private Token rightParent;
    private Stmt first;
    private Token elseTk;
    private Stmt second;

    public IfElseStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public IfElseStmt parseIfElseStmt() {
        // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        ifTk = iterator.getNextToken();
        leftParent = iterator.getNextToken();
        CondParser parser = new CondParser(iterator);
        cond = parser.parseCond();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.RPARENT) {
            rightParent = t1;
        } else {
            iterator.ungetToken(2);
            Token t2 = iterator.getNextToken();
            Error error = new Error(t2.getLineNum(), "j");
            ErrorList.addErrorList(error);
            rightParent = null;
        }
        StmtParser stmtParser = new StmtParser(iterator);
        first = stmtParser.parseStmt();
        Token t3 = iterator.getNextToken();
        if (t3.getType() == TokenType.ELSETK) {
            elseTk = t3;
            StmtParser parser1 = new StmtParser(iterator);
            second = parser1.parseStmt();
        } else {
            iterator.ungetToken(1);
            elseTk = null;
            second = null;
        }
        return new IfElseStmt(ifTk, leftParent, cond, rightParent, first, elseTk, second);
    }
}
