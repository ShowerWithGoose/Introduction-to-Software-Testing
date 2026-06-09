package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class MulExp {
    public static final LexType[] FIRST = UnaryExp.FIRST;

    private final MulExp mulExp;
    private final LexType lexType;
    private final UnaryExp unaryExp;

    public MulExp(UnaryExp unaryExp) {
        this.mulExp = null;
        this.lexType = null;
        this.unaryExp = Objects.requireNonNull(unaryExp);
        Logger.logGood("<MulExp>\n");
    }

    public MulExp(MulExp mulExp, LexType lexType, UnaryExp unaryExp) {
        this.mulExp = Objects.requireNonNull(mulExp);
        this.lexType = Objects.requireNonNull(lexType);
        this.unaryExp = Objects.requireNonNull(unaryExp);
        if (lexType != LexType.MULT && lexType != LexType.DIV && lexType != LexType.MOD) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<MulExp>\n");
    }

    public UnaryExp getUnaryExp() {
        if (mulExp != null) {
            throw new RuntimeException();
        }
        return unaryExp;
    }
}
