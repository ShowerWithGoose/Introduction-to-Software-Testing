package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.terminal.IntConst;
import frontend.parser.terminal.IntConstParser;

import java.util.ArrayList;

public class NumberParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public NumberParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Number parseNumber() {
        IntConstParser intConstParser = new IntConstParser(this.iterator,this.error_tokens);
        IntConst intConst = intConstParser.parseIntConst();
        Number number = new Number(intConst);
        return number;
    }
}
