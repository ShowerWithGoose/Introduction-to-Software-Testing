package frontend.nodes;

import frontend.*;

public class BType extends Node {
    public BType() {
        super(NodeType.B_TYPE);
    }

    public static Node parse() {
        BType bType = new BType();
        if (Lexer.INSTANCE.getLexType() == LexType.INTTK ||
            Lexer.INSTANCE.getLexType() == LexType.CHARTK) {
            bType.parseAndAdd(NodeRegistry.TERMINAL);
        } else {
            processError(ErrorType.NONE);
        }
        return bType;
    }
}
