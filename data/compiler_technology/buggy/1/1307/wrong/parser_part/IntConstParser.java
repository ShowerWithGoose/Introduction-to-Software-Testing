package parser_part;

import lexer_part.TokenList;
import lexer_part.Token;

public class IntConstParser {
    private TokenList tokenList;

    public IntConstParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public IntConst parseIntConst() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.INTCON) {
            //System.err.println("expect intcon in parseIntConst");
        }
        return new IntConst(token);
    }
}
