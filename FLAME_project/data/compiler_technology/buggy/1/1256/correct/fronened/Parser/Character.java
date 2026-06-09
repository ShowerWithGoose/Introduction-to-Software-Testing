package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class Character {
    private Token token;

    public Character(Token token) {
        this.token = token;
    }

    public static Character parser(TokenIterator iterator) {
        Token token = iterator.next();
        return new Character(token);
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.print());
        sb.append("<Character>\n");
        return sb.toString();
    }
}
