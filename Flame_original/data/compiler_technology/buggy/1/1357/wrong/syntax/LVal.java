package syntax;

import lexer.LexType;
import logger.Logger;

public class LVal {
    public static final LexType[] FIRST = {
            LexType.IDENFR
    };

    private final String name;
    private final Exp exp;

    public LVal(String name, Exp exp) {
        this.name = name;
        this.exp = exp;
        Logger.logGood("<LVal>\n");
    }
}
