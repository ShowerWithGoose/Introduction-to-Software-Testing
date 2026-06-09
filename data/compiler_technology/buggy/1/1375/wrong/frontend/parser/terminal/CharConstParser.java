package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class CharConstParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* IntConst */
    public Token token = null;

    public CharConstParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public CharConst parseCharConst() {
        this.token = this.iterator.readNextToken();
        if (!this.token.type.equals(TokenType.CHRCON)) {
            System.out.println("EXPECT CharConst HERE");
        }
        CharConst charConst = new CharConst(this.token);
        return charConst;
    }
}
