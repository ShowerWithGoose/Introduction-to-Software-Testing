package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class LOrExp {
    public static final LexType[] FIRST = LAndExp.FIRST;

    private final LOrExp lOrExp;
    private final LAndExp lAndExp;

    public LOrExp(LAndExp lAndExp) {
        this.lOrExp = null;
        this.lAndExp = Objects.requireNonNull(lAndExp);
        Logger.logGood("<LOrExp>\n");
    }

    public LOrExp(LOrExp lOrExp, LAndExp lAndExp) {
        this.lOrExp = Objects.requireNonNull(lOrExp);
        this.lAndExp = Objects.requireNonNull(lAndExp);
        Logger.logGood("<LOrExp>\n");
    }
}
