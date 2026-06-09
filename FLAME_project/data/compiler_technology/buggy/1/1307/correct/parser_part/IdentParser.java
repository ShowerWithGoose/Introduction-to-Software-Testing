package parser_part;

import lexer_part.Token;
import lexer_part.TokenList;

public class IdentParser {
    private TokenList tokenList;

    public IdentParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public Ident parseIdent() {
        Token token = tokenList.getNextToken();
        /*if (token.getIRType() != Token.TokenType.IDENFR) {
            System.err.println("expect identTK in parseIdent");
        }*/
        return new Ident(token);
    }
}
