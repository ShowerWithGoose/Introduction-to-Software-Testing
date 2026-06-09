package syntax;

import lexer.LexType;
import logger.Logger;

public class FuncType {
    public static final LexType[] FIRST = {
            LexType.VOIDTK, LexType.INTTK, LexType.CHARTK
    };

    private final LexType lexType;

    public FuncType(LexType lexType) {
        if (lexType != LexType.VOIDTK && lexType != LexType.INTTK && lexType != LexType.CHARTK) {
            throw new RuntimeException();
        }
        this.lexType = lexType;
        Logger.logGood("<FuncType>\n");
    }
}
