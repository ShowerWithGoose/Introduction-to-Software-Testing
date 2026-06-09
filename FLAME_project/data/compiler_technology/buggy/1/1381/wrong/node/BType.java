package node;

import frontend.Parser;
import frontend.Token;

public class BType {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.BType;
    private Token.TokenType type;

    public BType(Token.TokenType type) {
        this.type = type;
    }

    public Token.TokenType getType() {
        return type;
    }
    
    public String toString() {
        return "<" + type + ">";
    }
}
