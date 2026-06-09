package syntax;

import lexer.LexType;
import logger.Logger;

public class Number {
    public static final LexType[] FIRST = {
            LexType.INTCON
    };

    private final int value; // 32 位有符号整数

    public Number(int value) {
        this.value = value;
        Logger.logGood("<Number>\n");
    }
}
