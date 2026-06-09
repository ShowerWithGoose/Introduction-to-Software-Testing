package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class AddExp {
    public static final LexType[] FIRST = MulExp.FIRST;

    private final AddExp addExp;
    private final LexType lexType;
    private final MulExp mulExp;

    public AddExp(MulExp mulExp) {
        this.addExp = null;
        this.lexType = null;
        this.mulExp = Objects.requireNonNull(mulExp);
        Logger.logGood("<AddExp>\n");
    }

    public AddExp(AddExp addExp, LexType lexType, MulExp mulExp) {
        this.addExp = Objects.requireNonNull(addExp);
        this.lexType = Objects.requireNonNull(lexType);
        this.mulExp = Objects.requireNonNull(mulExp);
        if (lexType != LexType.PLUS && lexType != LexType.MINU) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<AddExp>\n");
    }

    public MulExp getMulExp() {
        if (addExp != null) {
            throw new RuntimeException();
        }
        return mulExp;
    }
}
