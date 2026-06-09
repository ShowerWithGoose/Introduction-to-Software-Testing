package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class PrimaryExp {
    public static final LexType[] FIRST = Stream.concat(
            Stream.concat(Arrays.stream(new LexType[] {LexType.LPARENT}), Arrays.stream(LVal.FIRST)), Stream.concat(Arrays.stream(Number.FIRST), Arrays.stream(Character.FIRST))
    ).toArray(LexType[]::new);

    private final Exp exp;
    private final LVal lVal;
    private final Number number;
    private final Character character;

    public PrimaryExp(Exp exp) {
        this.exp = Objects.requireNonNull(exp);
        this.lVal = null;
        this.number = null;
        this.character = null;
        Logger.logGood("<PrimaryExp>\n");
    }

    public PrimaryExp(LVal lVal) {
        this.exp = null;
        this.lVal = Objects.requireNonNull(lVal);
        this.number = null;
        this.character = null;
        Logger.logGood("<PrimaryExp>\n");
    }

    public PrimaryExp(Number number) {
        this.exp = null;
        this.lVal = null;
        this.number = Objects.requireNonNull(number);
        this.character = null;
        Logger.logGood("<PrimaryExp>\n");
    }

    public PrimaryExp(Character character) {
        this.exp = null;
        this.lVal = null;
        this.number = null;
        this.character = Objects.requireNonNull(character);
        Logger.logGood("<PrimaryExp>\n");
    }

    public LVal getlVal() {
        if (lVal == null) {
            throw new RuntimeException();
        }
        return lVal;
    }
}
