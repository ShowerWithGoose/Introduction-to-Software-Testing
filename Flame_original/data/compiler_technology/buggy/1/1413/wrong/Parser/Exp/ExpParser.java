package Parser.Exp;

import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class ExpParser {
    private TokenListIterator iterator;
    private AddExp addExp;

    public ExpParser(TokenListIterator iterator) {
        this.iterator=iterator;
    }
    public Exp expParse(){
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        AddExp addExp = addExpParser.AddExpparse();
        return new Exp(addExp);
    }
}
