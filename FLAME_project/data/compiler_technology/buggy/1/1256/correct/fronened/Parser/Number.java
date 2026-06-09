package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class Number {
    private Token token;

    public Number(Token token) {
        this.token = token;
    }

    public static Number parser(TokenIterator iterator) {
        Token token = iterator.next();
            return new Number(token);
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.print());
        sb.append("<Number>\n");
        return sb.toString();
    }
}
