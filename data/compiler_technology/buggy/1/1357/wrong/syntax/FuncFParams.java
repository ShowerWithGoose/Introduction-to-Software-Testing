package syntax;

import lexer.LexType;
import logger.Logger;

public class FuncFParams {
    public static final LexType[] FIRST = FuncFParam.FIRST;

    private final FuncFParam[] funcFParams;

    public FuncFParams(FuncFParam[] funcFParams) {
        this.funcFParams = funcFParams;
        Logger.logGood("<FuncFParams>\n");
    }
}
