package parser_part.expression.primaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.FloatConstParser;
import parser_part.IntConstParser;

public class NumberParser {
    private TokenList tokenList;

    public NumberParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public Number parseNumber() {
        NumberComponent numberComponent = null;
        Token token = tokenList.getNextToken();
        tokenList.moveBack(1);
        if (token.getType() == Token.TokenType.INTCON) {
            IntConstParser intConstParser = new IntConstParser(tokenList);
            numberComponent = intConstParser.parseIntConst();
        } else if (token.getType() == Token.TokenType.FLOATCON) {
            FloatConstParser floatConstParser = new FloatConstParser(tokenList);
            numberComponent = floatConstParser.parseFloatConst();
        }
        return new Number(numberComponent);
    }
}
