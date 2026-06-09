package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.io.FileWriter;
import java.io.IOException;

public class BType {
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    public static BType parser(TokenIterator iterator) {
        Token token = iterator.next();
        return new BType(token);
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.print());
        return sb.toString();
    }

}
