package frontend.parser.expression;

import frontend.lexer.TokenIterator;
import frontend.parser.expression.lOrExp.LOrExp;
import frontend.parser.expression.lOrExp.LOrExpParser;

public class CondParser {
    private TokenIterator iterator;
    private LOrExp lOrExp;

    public CondParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public Cond parseCond() {
        LOrExpParser parser = new LOrExpParser(iterator);
        lOrExp = parser.parseLOrExp();
        return new Cond(lOrExp);
    }
}
