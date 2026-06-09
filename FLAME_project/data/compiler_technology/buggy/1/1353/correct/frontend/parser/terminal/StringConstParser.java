package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

public class StringConstParser {
    private TokenListIterator iterator;
    /* StringConst */
    private Token token = null;

    public StringConstParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StringConst parseStringConst() {
        this.token = this.iterator.next();
        if (!this.token.getTokenType().equals(TokenType.STRCON)) {
            System.out.println("EXPECT STRCON HERE");
        }
        StringConst stringConst = new StringConst(this.token);
        return stringConst;
    }
}
