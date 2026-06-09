package frontend.parser.expression.primaryExp;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

public class ExpBraceParser {

    //j-error
    private TokenIterator iterator;
    private Token leftParent;
    private Token rightParent;
    private Exp exp;

    public ExpBraceParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ExpBrace parseExpBrace() {
        leftParent = iterator.getNextToken();
        ExpParser expParser = new ExpParser(iterator);
        exp = expParser.parseExp();
        Token t1 = iterator.getNextToken();
        if (t1.getType() != TokenType.RPARENT) {
            //缺少）
            iterator.ungetToken(2);
            Token t2 = iterator.getNextToken();
            Error error = new Error(t2.getLineNum(), "j");
            ErrorList.addErrorList(error);
            rightParent = null;
        } else {
            rightParent = t1;
        }
        return new ExpBrace(leftParent, rightParent, exp);
    }
}
