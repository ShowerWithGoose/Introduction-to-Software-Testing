package frontend.Parser.Terminators;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class BType implements ASTNode {
    private Token token;    // INTTK CHARTK

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        return token.toString();
    }
}
