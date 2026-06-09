package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Arrays;
import java.util.Objects;
import java.util.stream.Stream;

public class UnaryExp {
    public static final LexType[] FIRST = Stream.concat(
            Stream.concat(Arrays.stream(PrimaryExp.FIRST), Arrays.stream(new LexType[] {LexType.IDENFR})), Arrays.stream(UnaryOp.FIRST)
    ).toArray(LexType[]::new);

    private final PrimaryExp primaryExp;
    private final String name;
    private final FuncRParams funcRParams;
    private final UnaryOp unaryOp;
    private final UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = Objects.requireNonNull(primaryExp);
        this.name = null;
        this.funcRParams = null;
        this.unaryOp = null;
        this.unaryExp = null;
        Logger.logGood("<UnaryExp>\n");
    }

    public UnaryExp(String name, FuncRParams funcRParams) {
        this.primaryExp = null;
        this.name = Objects.requireNonNull(name);
        this.funcRParams = funcRParams;
        this.unaryOp = null;
        this.unaryExp = null;
        Logger.logGood("<UnaryExp>\n");
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.primaryExp = null;
        this.name = null;
        this.funcRParams = null;
        this.unaryOp = Objects.requireNonNull(unaryOp);
        this.unaryExp = Objects.requireNonNull(unaryExp);
        Logger.logGood("<UnaryExp>\n");
    }

    public PrimaryExp getPrimaryExp() {
        if (primaryExp == null) {
            throw new RuntimeException();
        }
        return primaryExp;
    }
}
