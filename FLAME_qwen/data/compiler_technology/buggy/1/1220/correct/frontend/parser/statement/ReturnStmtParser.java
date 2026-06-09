package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class ReturnStmtParser {
    private TokenIterator iterator;
    private Token returnTk;
    private Exp exp;
    private Token semicn;

    public ReturnStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ReturnStmt parseReturnStmt() {
        //'return' [Exp] ';'
        //First(Exp)='(',Ident,Number,Character,+,-,!
        returnTk = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.SEMICN) {
            exp = null;
            semicn = t1;
        } else if (t1.getType() == TokenType.LPARENT || t1.getType() == TokenType.IDENFR
        || t1.getType() == TokenType.INTCON || t1.getType() == TokenType.CHRCON || t1.getType() == TokenType.PLUS
        || t1.getType() == TokenType.MINU || t1.getType() == TokenType.NOT) {
            iterator.ungetToken(1);
            ExpParser expParser = new ExpParser(iterator);
            exp = expParser.parseExp();
            semicn = iterator.getNextToken();
            if (semicn.getType() != TokenType.SEMICN) {
                semicn = null;
                iterator.ungetToken(2);
                Error error = new Error(iterator.getNextToken().getLineNum(), "i");
                ErrorList.addErrorList(error);
            }
        }
        else {
            //缺少分号,exp
            exp = null;
            semicn = null;
            iterator.ungetToken(2);
            Error error = new Error(iterator.getNextToken().getLineNum(), "i");
            ErrorList.addErrorList(error);
        }
        return new ReturnStmt(returnTk, exp, semicn);
    }
}
