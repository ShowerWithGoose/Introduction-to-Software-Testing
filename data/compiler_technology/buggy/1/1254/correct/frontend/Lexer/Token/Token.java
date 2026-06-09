package frontend.Lexer.Token;

import frontend.Parser.SyntaxNode.SyntaxNode;

public class Token implements SyntaxNode {
    private final TokenType type;
    private final String content;
    private final int lineNum;

    public Token(TokenType type, String content, int lineNum) {
        this.type = type;
        this.content = content;
        this.lineNum = lineNum;
    }

    public Token(String content, int lineNum) {
        this.type = TokenType.keyWordMap.get(content);
        this.content = content;
        this.lineNum = lineNum;
    }

    public int getLineNum() {
        return lineNum;
    }

    public TokenType getType() {
        return type;
    }

    public boolean isType(TokenType type) {
        return this.type == type;
    }

    @Override
    public String toString() {
        return type.toString() + " " + content + "\n";
    }
}
