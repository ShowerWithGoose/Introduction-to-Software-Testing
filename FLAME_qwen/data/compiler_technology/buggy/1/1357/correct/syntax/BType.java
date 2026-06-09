package syntax;

import lexer.LexType;

public class BType {
    public static final LexType[] FIRST = {
            LexType.INTTK, LexType.CHARTK
    };

    private final LexType lexType;

    public BType(LexType lexType) {
        if (lexType != LexType.INTTK && lexType != LexType.CHARTK) {
            throw new RuntimeException();
        }
        this.lexType = lexType;
//        Constant.good.append("<BType>\n");
    }
}
