package frontend.Parser.Terminators;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class IntConst implements ASTNode {
    private Token token;    // INTCON

    public IntConst(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        return token.toString();
    }
}
