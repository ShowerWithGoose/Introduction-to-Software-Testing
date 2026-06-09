package parser_part.declaration;

import lexer_part.Token;
import parser_part.Node;

public class BType implements Node {
    private Token token; // INTTK and FLOATTK

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString();
    }
    public boolean isChar(){
        return token.getType() == Token.TokenType.CHARTK;
    }

    public boolean isInt(){
        return token.getType() == Token.TokenType.INTTK;
    }
}
