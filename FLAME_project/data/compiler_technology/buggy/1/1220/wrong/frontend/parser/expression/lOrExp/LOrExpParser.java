package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class LOrExpParser {
    private TokenIterator iterator;
    private LAndExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<LAndExp> lAndExps = new ArrayList<>();

    public LOrExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public LOrExp parseLOrExp() {
        //LOrExp -> LAndExp {|| LAndExp}
        LAndExpParser parser = new LAndExpParser(iterator);
        first = parser.parseLAndExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.OR) {
            ops.add(t1);
            LAndExpParser parser1 = new LAndExpParser(iterator);
            lAndExps.add(parser1.parseLAndExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new LOrExp(first, ops, lAndExps);

    }
}
