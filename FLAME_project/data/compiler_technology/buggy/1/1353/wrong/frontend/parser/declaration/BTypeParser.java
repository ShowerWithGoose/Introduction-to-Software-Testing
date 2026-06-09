package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

/**
 * BTypeParser 基本类型解析器类
 * <BType> -> 'int | 'char'
 */
public class BTypeParser {
    private TokenListIterator iterator;

    public BTypeParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public BType parseBtype() {
        Token first = this.iterator.next();
        if (!(first.getTokenType().equals(TokenType.INTTK) || first.getTokenType().equals(TokenType.CHARTK))) {
            System.out.println("ERROR : EXPECT INTTK or CHARTK");
            iterator.unRead(1);
        }
        BType btype = new BType(first);
        return btype;
    }
}
