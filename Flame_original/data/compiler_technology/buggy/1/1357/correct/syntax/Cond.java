package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class Cond {
    public static final LexType[] FIRST = LOrExp.FIRST;

    private final LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = Objects.requireNonNull(lOrExp);
        Logger.logGood("<Cond>\n");
    }
}
