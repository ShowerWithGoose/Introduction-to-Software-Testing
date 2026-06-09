package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class RelExpParser {
    private TokenIterator iterator;
    private AddExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<AddExp> addExps = new ArrayList<>();

    public RelExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public RelExp parseRelExp() {
        ////RelExp->AddExp {('<'|'>'|'<='|'>=')AddExp}
        AddExpParser parser = new AddExpParser(iterator);
        first = parser.parseAddExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.LSS || t1.getType() == TokenType.LEQ
        || t1.getType() == TokenType.GRE || t1.getType() == TokenType.GEQ) {
            ops.add(t1);
            AddExpParser parser1 = new AddExpParser(iterator);
            addExps.add(parser1.parseAddExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new RelExp(first, ops, addExps);
    }
}

