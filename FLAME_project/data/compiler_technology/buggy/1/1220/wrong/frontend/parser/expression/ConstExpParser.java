package frontend.parser.expression;

import frontend.lexer.TokenIterator;
import frontend.parser.expression.lOrExp.AddExp;
import frontend.parser.expression.lOrExp.AddExpParser;

public class ConstExpParser {
    private TokenIterator iterator;
    private AddExp addExp;

    public ConstExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ConstExp parseConstExp() {
        //ConstExp â†’ AddExp
        AddExpParser addExpParser = new AddExpParser(iterator);
        addExp = addExpParser.parseAddExp();
        return new ConstExp(addExp);
    }
}
