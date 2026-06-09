package syntaxTree;

import token.Token;
import token.TokenType;

public class FuncFParam {
    private final TokenType bType;
    private final Token ident;
    private final boolean isArray;

    public FuncFParam(TokenType bType, Token ident, boolean isArray) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
    }
}
