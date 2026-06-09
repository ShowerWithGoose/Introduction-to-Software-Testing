package frontend.nodes;

import frontend.*;

public class LVal extends Node {
    public LVal() {
        super(NodeType.L_VAL);
    }

    public static Node parse() {
        LVal lVal = new LVal();
        lVal.terminalCheck(LexType.IDENFR);
        if (Lexer.INSTANCE.getLexType() == LexType.LBRACK) {
            lVal.parseAndAdd(NodeRegistry.TERMINAL);
            lVal.parseAndAdd(NodeRegistry.EXP);
            lVal.terminalCheck(LexType.RBRACK, ErrorType.k);
        }
        return lVal;
    }
}
