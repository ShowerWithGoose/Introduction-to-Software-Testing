package syntax;
import lexer.LexType;
import logger.Logger;

public class UnaryOp {
    public static final LexType[] FIRST = {
            LexType.PLUS, LexType.MINU, LexType.NOT
    };
    private final LexType lexType;

    public UnaryOp(LexType lexType) {
        if (lexType != LexType.PLUS && lexType != LexType.MINU && lexType != LexType.NOT) {
            throw new RuntimeException();
        }
        this.lexType = lexType;
        Logger.logGood("<UnaryOp>\n");
    }
}
