package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.parser.expression.multiexp.LOrExp;
import frontend.parser.expression.multiexp.LOrExpParser;

import java.util.ArrayList;

public class CondParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public CondParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public Cond parseCond() {
        LOrExpParser lorExpParser = new LOrExpParser(this.iterator,this.error_tokens);
        LOrExp lorExp = lorExpParser.parseLOrExp();
        Cond cond = new Cond(lorExp);
        return cond;
    }
}
