package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class FuncRParamsParser {
    private TokenIterator iterator;
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParamsParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public FuncRParams parseFuncRParams() {
        // FuncRParams â†’ Exp { ',' Exp }
        ExpParser parser = new ExpParser(iterator);
        first = parser.parseExp();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.COMMA) {
            commas.add(t1);
            ExpParser parser1 = new ExpParser(iterator);
            exps.add(parser1.parseExp());
            t1 = iterator.getNextToken();
        }
        iterator.ungetToken(1);
        return new FuncRParams(first, commas, exps);
    }
}
