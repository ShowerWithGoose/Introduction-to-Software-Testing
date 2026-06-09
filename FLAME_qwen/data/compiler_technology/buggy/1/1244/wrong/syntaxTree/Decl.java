package syntaxTree;

import token.TokenType;

public abstract class Decl extends BlockItem {
    private final TokenType bType;

    public Decl(TokenType bType) {
        this.bType = bType;
    }
}
