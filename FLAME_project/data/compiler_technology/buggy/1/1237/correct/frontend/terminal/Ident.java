package frontend.terminal;

import frontend.Token;
import frontend.TokenType;
import frontend.SyntaxNode;

/**
 * 标识符 Identifier
 */
public class Ident implements SyntaxNode {
    private final Token token;

    public Ident(Token token) {
        if (token == null || token.getType() != TokenType.IDENFR) {
            throw new IllegalArgumentException("Token must be of type IDENFR");
        }
        this.token = token;
    }

    public Ident(String name, int lineIndex) {
        if (name == null || name.isEmpty()) {
            throw new IllegalArgumentException("Name cannot be null or empty");
        }
        this.token = new Token(TokenType.IDENFR, lineIndex, name);
    }

    public String getName() {
        return this.token.getContent();
    }

    public int getLineIndex() {
        return this.token.getLineIndex();
    }

    @Override
    public String syntaxOutput() {
        return token.syntaxOutput();
    }

    @Override
    public String toString() {
        return token.getContent();
    }
}