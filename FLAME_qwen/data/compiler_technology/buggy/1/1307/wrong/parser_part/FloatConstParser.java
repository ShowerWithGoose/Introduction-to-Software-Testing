package parser_part;

import lexer_part.Token;
import lexer_part.TokenList;

public class FloatConstParser {
    private TokenList tokenList;

    public FloatConstParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public FloatConst parseFloatConst() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.FLOATCON) {
            //System.err.println("expect floatcon in parseFloatConst");
        }
        return new FloatConst(token);
    }
}
