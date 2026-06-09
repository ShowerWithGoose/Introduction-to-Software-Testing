package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class InitVal {
    public static final LexType[] FIRST = Stream.concat(
            Arrays.stream(Exp.FIRST), Arrays.stream(new LexType[] {LexType.LBRACE, LexType.STRCON})
    ).toArray(LexType[]::new);

    private final Exp exp;
    private final Exp[] exps;
    private final String string;

    public InitVal(Exp exp) {
        this.exp = Objects.requireNonNull(exp);
        this.exps = null;
        this.string = null;
        Logger.logGood("<InitVal>\n");
    }

    public InitVal(Exp[] exps) {
        this.exp = null;
        this.exps = Objects.requireNonNull(exps);
        this.string = null;
        Logger.logGood("<InitVal>\n");
    }

    public InitVal(String string) {
        this.exp = null;
        this.exps = null;
        this.string = Objects.requireNonNull(string);
        Logger.logGood("<InitVal>\n");
    }
}
