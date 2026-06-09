package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class ConstInitVal {
    public static final LexType[] FIRST = Stream.concat(
            Arrays.stream(ConstExp.FIRST), Arrays.stream(new LexType[] {LexType.LBRACE, LexType.STRCON})
    ).toArray(LexType[]::new);

    private final ConstExp constExp;
    private final ConstExp[] constExps;
    private final String string;

    public ConstInitVal(ConstExp constExp) {
        this.constExp = Objects.requireNonNull(constExp);
        this.constExps = null;
        this.string = null;
        Logger.logGood("<ConstInitVal>\n");
    }

    public ConstInitVal(ConstExp[] constExps) {
        this.constExp = null;
        this.constExps = Objects.requireNonNull(constExps);
        this.string = null;
        Logger.logGood("<ConstInitVal>\n");
    }

    public ConstInitVal(String string) {
        this.constExp = null;
        this.constExps = null;
        this.string = Objects.requireNonNull(string);
        Logger.logGood("<ConstInitVal>\n");
    }
}
