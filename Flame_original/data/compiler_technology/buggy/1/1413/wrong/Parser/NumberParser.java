package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class NumberParser {
    private TokenListIterator iterator;
    private Token intConst;
    public NumberParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public NumberClass parseNumber(){
        this.intConst = this.iterator.readNextToken();
        if (!this.intConst.getType().equals("INTCON")) {
            System.out.println("EXPECT INTCON HERE");
            return null;
        }else {
            return new NumberClass(intConst);
        }
    }
}
