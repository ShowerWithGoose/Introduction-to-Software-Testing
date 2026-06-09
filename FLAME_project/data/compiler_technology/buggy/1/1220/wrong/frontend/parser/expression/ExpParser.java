package frontend.parser.expression;

import frontend.lexer.TokenIterator;
import frontend.parser.expression.lOrExp.AddExp;
import frontend.parser.expression.lOrExp.AddExpParser;

public class ExpParser {
    private TokenIterator iterator;
    private AddExp addExp;

    public ExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public Exp parseExp() {
        //Exp -> AddExp
        AddExpParser addExpParser = new AddExpParser(iterator);
        addExp = addExpParser.parseAddExp();
        return new Exp(addExp);
    }
}
