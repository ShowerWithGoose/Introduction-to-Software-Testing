package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class VarDef {
    public static final LexType[] FIRST = {
            LexType.IDENFR
    };

    private final String name;
    private final ConstExp constExp;
    private final InitVal initVal;

    public VarDef(String name, ConstExp constExp, InitVal initVal) {
        Objects.requireNonNull(name);

        this.name = name;
        this.constExp = constExp;
        this.initVal = initVal;
        Logger.logGood("<VarDef>\n");
    }
}
