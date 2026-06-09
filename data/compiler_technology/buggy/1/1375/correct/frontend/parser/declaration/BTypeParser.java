package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class BTypeParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public BTypeParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }
    public BType parseBtype() {
        Token first = this.iterator.readNextToken();
        if (!first.type.equals(TokenType.INTTK) && !first.type.equals(TokenType.CHARTK)) {
            System.out.println("ERROR : EXPECT INTTK OR CHARTK");
        }
        BType btype = new BType(first);
        return btype;
    }

}
