package syntax;

import lexer.LexType;
import logger.Logger;

public class ConstDecl {
    public static final LexType[] FIRST = {
            LexType.CONSTTK
    };

    private final BType bType;
    private final ConstDef[] constDefs;

    public ConstDecl(BType bType, ConstDef[] constDefs) {
        this.bType = bType;
        this.constDefs = constDefs;
        Logger.logGood("<ConstDecl>\n");
    }
}
