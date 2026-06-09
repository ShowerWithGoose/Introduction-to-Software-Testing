package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

public class IdentParser {
    private TokenListIterator iterator;
    /* Ident Attribute */
    private Token token; // ident

    public IdentParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Ident parseIdent() {
        token = this.iterator.next();
        if (!token.getTokenType().equals(TokenType.IDENFR)) {
            System.out.println("EXPECT IDENFR HERE");
        }
        Ident ident = new Ident(token);
        return ident;
    }
}
