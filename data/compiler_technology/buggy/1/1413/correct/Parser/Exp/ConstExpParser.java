package Parser.Exp;

import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/11
 */
public class ConstExpParser {
    private TokenListIterator iterator;
    /* ConstExp Attributes */
    private AddExp addExp = null;

    public ConstExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstExp parseConstExp() {
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        this.addExp = addExpParser.AddExpparse();
        ConstExp constExp = new ConstExp(this.addExp);
        return constExp;
    }
}
