package Parser.Exp;

import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class CondParser {
    private TokenListIterator iterator;
    private LOrExp lorExp;

    public CondParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Cond parseCond() {
        LOrExpParser lorExpParser = new LOrExpParser(this.iterator);
        this.lorExp = lorExpParser.lOrExpParse();
        return new Cond(lorExp);
    }
}
