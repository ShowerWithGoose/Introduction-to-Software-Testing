package frontend.Parser.Declaration;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class Ident implements ASTNode {
    private Token token;    // IDENFR

    public Ident(Token token) {
        this.token = token;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.toString());
        return sb.toString();
    }
}
