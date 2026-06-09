package fronted.parser;

import fronted.lexer.Token;
import fronted.lexer.TokenType;

public class TokenNode extends Node {
    //叶子节点
    public Token token;

    public TokenNode(int startLine, int endLine, SyntaxType type,Token token) {
        super(startLine, endLine, type);
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString();
    }

}
