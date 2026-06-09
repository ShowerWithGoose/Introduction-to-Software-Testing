package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class FuncRParams {
    public static final LexType[] FIRST = Exp.FIRST;

    private final Exp[] exps;

    public FuncRParams(Exp[] exps) {
        this.exps = Objects.requireNonNull(exps);
        if (exps.length == 0) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<FuncRParams>\n");
    }
}
