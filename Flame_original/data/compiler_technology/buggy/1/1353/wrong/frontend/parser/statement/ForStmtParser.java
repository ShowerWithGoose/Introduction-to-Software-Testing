package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.Iterator;

/**
 * ForStmtParser for语句解析器类
 * <ForStmt> -> <LVal> '=' <Exp>
 */
public class ForStmtParser {
    private TokenListIterator iterator;
    /* ForStmt Attributes */
    private LVal lVal;
    private Token assignTK; // '='
    private Exp exp;

    public ForStmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ForStmt parseForStmt() {
        LValParser lValParser = new LValParser(this.iterator);
        lVal = lValParser.parseLVal();
        assignTK = iterator.next();
        ExpParser expParser = new ExpParser(this.iterator);
        exp = expParser.parseExp();
        ForStmt forStmt = new ForStmt(this.lVal, this.assignTK, this.exp);
        return forStmt;
    }
}
