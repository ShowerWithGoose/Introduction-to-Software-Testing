package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class IntConstParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* IntConst */
    public Token token = null;

    public IntConstParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public IntConst parseIntConst() {
        this.token = this.iterator.readNextToken();
        if (!this.token.type.equals(TokenType.INTCON)) {
            System.out.println("EXPECT INTCON HERE");
        }
        IntConst intConst = new IntConst(this.token);
        return intConst;
    }
}
