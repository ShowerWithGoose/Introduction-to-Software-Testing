package frontend.Parser.Terminators;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class CharConst implements ASTNode {
    private Token token;    // CHRCON

    public CharConst(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        return token.toString();
    }
}
