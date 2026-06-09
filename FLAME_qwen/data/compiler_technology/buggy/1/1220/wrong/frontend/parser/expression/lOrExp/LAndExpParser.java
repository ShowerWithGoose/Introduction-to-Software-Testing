package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class LAndExpParser {
    private TokenIterator iterator;
    private EqExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<EqExp> eqExps = new ArrayList<>();

    public LAndExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public LAndExp parseLAndExp() {
        //LAndExp -> EqExp {&& EqExp}
        EqExpParser parser = new EqExpParser(iterator);
        first = parser.parseEqExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.AND) {
            ops.add(t1);
            EqExpParser parser1 = new EqExpParser( iterator);
            eqExps.add(parser1.parseEqExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new LAndExp(first, ops, eqExps);
    }
}
