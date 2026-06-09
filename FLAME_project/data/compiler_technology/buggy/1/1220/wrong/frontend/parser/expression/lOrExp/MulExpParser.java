package frontend.parser.expression.lOrExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.unaryExp.UnaryExp;
import frontend.parser.expression.unaryExp.UnaryExpParser;

import java.util.ArrayList;

public class MulExpParser {
    private TokenIterator iterator;
    private UnaryExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExps = new ArrayList<>();

    public MulExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public MulExp parseMulExp() {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        // MulExp —> UnaryExp{('*'|'/'|'%')UnaryExp}
        UnaryExpParser parser = new UnaryExpParser(iterator);
        first = parser.parseUnaryExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.MULT || t1.getType() == TokenType.DIV
        || t1.getType() == TokenType.MOD) {
            ops.add(t1);
            UnaryExpParser parser1 = new UnaryExpParser(iterator);
            unaryExps.add(parser1.parseUnaryExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new MulExp(first, ops, unaryExps);
    }
}
