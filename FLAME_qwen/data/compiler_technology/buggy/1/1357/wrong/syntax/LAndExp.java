package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class LAndExp {
    public static final LexType[] FIRST = EqExp.FIRST;

    private final LAndExp lAndExp;
    private final EqExp eqExp;

    public LAndExp(EqExp eqExp) {
        this.lAndExp = null;
        this.eqExp = Objects.requireNonNull(eqExp);
        Logger.logGood("<LAndExp>\n");
    }

    public LAndExp(LAndExp lAndExp, EqExp eqExp) {
        this.lAndExp = Objects.requireNonNull(lAndExp);
        this.eqExp = Objects.requireNonNull(eqExp);
        Logger.logGood("<LAndExp>\n");
    }
}
