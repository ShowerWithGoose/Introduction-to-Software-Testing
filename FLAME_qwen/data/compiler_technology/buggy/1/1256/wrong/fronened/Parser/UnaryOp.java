package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class UnaryOp {
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.print());
        sb.append("<UnaryOp>\n");
        return sb.toString();
    }

    public static UnaryOp parse(TokenIterator iterator) {
        Token token = iterator.next();
        return new UnaryOp(token);
    }
}
