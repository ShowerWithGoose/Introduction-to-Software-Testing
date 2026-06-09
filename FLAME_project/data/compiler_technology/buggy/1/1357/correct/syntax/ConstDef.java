package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class ConstDef {
    public static final LexType[] FIRST = {
            LexType.IDENFR
    };

    private final String name;
    private final ConstExp constExp;
    private final ConstInitVal constInitVal;

    public ConstDef(String name, ConstExp constExp, ConstInitVal constInitVal) {
        this.name = Objects.requireNonNull(name);
        this.constExp = constExp;
        this.constInitVal = Objects.requireNonNull(constInitVal);
        Logger.logGood("<ConstDef>\n");
    }
}
