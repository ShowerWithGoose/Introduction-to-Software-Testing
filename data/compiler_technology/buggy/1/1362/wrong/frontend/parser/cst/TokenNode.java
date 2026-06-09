package frontend.parser.cst;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

public class TokenNode extends CSTNode{
    private final Token token;
    private final boolean miss;
    
    public TokenNode(Token token) {
        this.token = token;
        this.miss = false;
    }
    
    public TokenNode(Token token, boolean miss) {
        this.token = token;
        this.miss = miss;
    }
    
    public Token getToken() {
        return token;
    }
    
    public int getLineNum() {
        return token.getLineNum();
    }
    
    public String getContent() {
        return token.getContent();
    }
    
    public boolean isSameType(TokenType tokenType) {
        return token.getType() == tokenType;
    }
    
    @Override
    public String toString() {
        return getContent();
    }
}
