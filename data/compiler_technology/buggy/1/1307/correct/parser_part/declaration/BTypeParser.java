package parser_part.declaration;

import lexer_part.Token;
import lexer_part.TokenList;

public class BTypeParser {
    private TokenList tokenList;

    public BTypeParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public BType parseBType() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.INTTK
                && token.getType() != Token.TokenType.FLOATTK
                && token.getType() != Token.TokenType.CHARTK) {
            System.err.println("expect 'int' or 'float' in parseBType");
        }
        return new BType(token);
    }
}
