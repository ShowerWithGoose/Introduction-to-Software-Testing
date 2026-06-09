package parser_part.expression.primaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.IntConst;

public class CharacterParser {
    private TokenList tokenList;

    public CharacterParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public Character parseCharacter() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.CHRCON) {
            System.err.println("expect character in parseIntConst");
        }
        return new Character(token);
    }
}
