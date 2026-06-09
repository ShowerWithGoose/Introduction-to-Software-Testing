package frontend.terminal;

import frontend.Token;
import frontend.TokenType;
import frontend.SyntaxNode;

/**
 * 数值常量 Integer-Const
 */
public class IntConst implements SyntaxNode {
    private final Token token;

    public IntConst(Token token) {
        if (token == null || token.getType() != TokenType.INTCON) {
            throw new IllegalArgumentException("Token must be of type INTCON");
        }
        this.token = token;
    }

    public IntConst(String numStr, int lineNum) {
        if (numStr == null || numStr.isEmpty()) {
            throw new IllegalArgumentException("Number string cannot be null or empty");
        }
        this.token = new Token(TokenType.INTCON, lineNum, numStr);
    }

    public int getNum() {
        try {
            return Integer.parseInt(this.token.getContent());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid number format: " + this.token.getContent());
        }
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