package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class EqExpParser {
    private TokenIterator iterator;

    private RelExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<RelExp> relExps = new ArrayList<>();

    public EqExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public EqExp parseEqExp() {
        //RelExp{(==|!=)RelExp}
        RelExpParser parser = new RelExpParser(iterator);
        first = parser.parseRelExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.EQL || t1.getType() == TokenType.NEQ) {
            ops.add(t1);
            RelExpParser parser1 = new RelExpParser(iterator);
            relExps.add(parser1.parseRelExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new EqExp(first, ops, relExps);
    }
}
