package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class AddExpParser {
    private TokenIterator iterator;
    private MulExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<MulExp> mulExps = new ArrayList<>();

    public AddExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public AddExp parseAddExp() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        //MulExp {('+'|'-')MulExp}
        MulExpParser parser = new MulExpParser(iterator);
        first = parser.parseMulExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.PLUS ||
        t1.getType() == TokenType.MINU) {
            ops.add(t1);
            MulExpParser parser1 = new MulExpParser(iterator);
            mulExps.add(parser1.parseMulExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new AddExp(first, ops, mulExps);
    }
}
