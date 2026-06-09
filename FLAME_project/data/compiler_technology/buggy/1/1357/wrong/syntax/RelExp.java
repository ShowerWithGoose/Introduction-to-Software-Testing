package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class RelExp {
    public static final LexType[] FIRST = AddExp.FIRST;

    private final RelExp relExp;
    private final LexType lexType;
    private final AddExp addExp;

    public RelExp(AddExp addExp) {
        this.relExp = null;
        this.lexType = null;
        this.addExp = Objects.requireNonNull(addExp);
        Logger.logGood("<RelExp>\n");
    }

    public RelExp(RelExp relExp, LexType lexType, AddExp addExp) {
        this.relExp = Objects.requireNonNull(relExp);
        this.lexType = Objects.requireNonNull(lexType);
        this.addExp = Objects.requireNonNull(addExp);
        if (lexType != LexType.LSS && lexType != LexType.GRE && lexType != LexType.LEQ && lexType != LexType.GEQ) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<RelExp>\n");
    }
}
