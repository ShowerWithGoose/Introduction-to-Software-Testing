package frontend.parser.expression.primaryExp;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class LValParser {
    //k-error
    private TokenIterator iterator;
    private Token ident;
    private Token leftBracket = null;
    private Token rightBracket = null;
    private Exp exp = null;

    public LValParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public LVal parseLVal() {
        // LVal → Ident ['[' Exp ']']
        ident = iterator.getNextToken();
        if (ident.getLineNum() == 59) {
            int a = 1;
        }
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.LBRACK) {
            leftBracket = t1;
            ExpParser parser = new ExpParser(iterator);
            exp = parser.parseExp();
            Token t2 = iterator.getNextToken();
            if (t2.getType() != TokenType.RBRACK) {
                //缺失]
                iterator.ungetToken(2);
                Token t3 = iterator.getNextToken();
                Error error = new Error(t3.getLineNum(), "k");
                ErrorList.addErrorList(error);
                rightBracket = null;
            } else {
                rightBracket = t2;
            }
        } else {
            iterator.ungetToken(1);
        }
        return new LVal(ident, leftBracket, rightBracket, exp);
    }
}
