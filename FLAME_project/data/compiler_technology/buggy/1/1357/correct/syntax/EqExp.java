package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class EqExp {
    public static final LexType[] FIRST = RelExp.FIRST;

    private final EqExp eqExp;
    private final LexType lexType;
    private final RelExp relExp;

    public EqExp(RelExp relExp) {
        this.eqExp = null;
        this.lexType = null;
        this.relExp = Objects.requireNonNull(relExp);
        Logger.logGood("<EqExp>\n");
    }

    public EqExp(EqExp eqExp, LexType lexType, RelExp relExp) {
        this.eqExp = Objects.requireNonNull(eqExp);
        this.lexType = Objects.requireNonNull(lexType);
        this.relExp = Objects.requireNonNull(relExp);
        if (lexType != LexType.EQL && lexType != LexType.NEQ) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<EqExp>\n");
    }
}
