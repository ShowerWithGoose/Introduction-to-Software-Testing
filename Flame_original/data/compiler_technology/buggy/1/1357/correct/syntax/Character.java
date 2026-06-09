package syntax;

import lexer.LexType;
import logger.Logger;

public class Character {
    public static final LexType[] FIRST = {
        LexType.CHRCON
    };

    private final char value; // 8 位无符号整数

    public Character(char value) {
        this.value = value;
        Logger.logGood("<Character>\n");
    }
}
