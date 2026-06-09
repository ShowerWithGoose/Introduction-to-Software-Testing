package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;

import java.util.ArrayList;

public class ConstInitValStringParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public Token token = null;
    public ConstInitValStringParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }
    public ConstInitValString parseConstInitValString() {
        this.token = this.iterator.readNextToken();
        ConstInitValString constInitValString =
                new ConstInitValString(this.token);
        return constInitValString;
    }
}
