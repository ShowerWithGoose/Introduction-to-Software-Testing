package syntax;

import lexer.LexType;
import logger.Logger;

public class FuncFParam {
    public static final LexType[] FIRST = BType.FIRST;

    private final BType bType;
    private final String name;
    private final boolean array;

    public FuncFParam(BType bType, String name, boolean array) {
        this.bType = bType;
        this.name = name;
        this.array = array;
        Logger.logGood("<FuncFParam>\n");
    }
}
