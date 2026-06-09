package syntax;

import lexer.LexType;
import logger.Logger;

import java.util.Objects;

public class VarDecl {
    public static final LexType[] FIRST = BType.FIRST;

    private final BType bType;
    private final VarDef[] varDefs;

    public VarDecl(BType bType, VarDef[] varDefs) {
        this.bType = Objects.requireNonNull(bType);
        this.varDefs = Objects.requireNonNull(varDefs);
        if (varDefs.length == 0) {
            throw new IllegalArgumentException();
        }
        Logger.logGood("<VarDecl>\n");
    }
}
