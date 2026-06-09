package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryExp.LVal;
import frontend.parser.expression.primaryExp.LValParser;

public class ForStmtParser {
    private TokenIterator iterator;
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ForStmt parseForStmt() {
        // ForStmt â†’ LVal '=' Exp /
        LValParser lValParser = new LValParser(iterator);
        lVal = lValParser.parseLVal();
        Token t1 = iterator.getNextToken();
        if (t1.getType() != TokenType.ASSIGN) {
            System.out.println("parseForStmt-WA");
            return null;
        }
        assign = t1;
        ExpParser expParser = new ExpParser(iterator);
        exp = expParser.parseExp();
        return new ForStmt(lVal, assign, exp);
    }
}
