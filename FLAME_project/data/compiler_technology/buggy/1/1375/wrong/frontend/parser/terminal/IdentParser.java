package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class IdentParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* Ident Attribute */
    public Token token; // ident

    public IdentParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Ident parseIdent() {
        token = this.iterator.readNextToken();
        if (!token.type.equals(TokenType.IDENFR)) {
            System.out.println("EXPECT IDENFR HERE");
        }
        Ident ident = new Ident(token);
        return ident;
    }
}
