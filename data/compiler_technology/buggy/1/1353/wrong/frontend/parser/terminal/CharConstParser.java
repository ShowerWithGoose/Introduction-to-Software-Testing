package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

public class CharConstParser {
    private TokenListIterator iterator;
    /* CharConst */
    private Token token = null;

    public CharConstParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public CharConst parseCharConst() {
        this.token = this.iterator.next();
        if (!this.token.getTokenType().equals(TokenType.CHRCON)) {
            System.out.println("EXPECT CHRCON HERE");
        }
        CharConst charConst = new CharConst(this.token);
        return charConst;
    }
}
