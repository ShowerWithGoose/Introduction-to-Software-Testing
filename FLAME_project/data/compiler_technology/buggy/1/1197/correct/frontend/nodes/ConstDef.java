package frontend.nodes;

import frontend.*;

public class ConstDef extends Node {
    public ConstDef() {
        super(NodeType.CONST_DEF);
    }

    public static Node parse() {
        ConstDef constDef = new ConstDef();
        constDef.terminalCheck(LexType.IDENFR);
        if (Lexer.INSTANCE.getLexType() == LexType.LBRACK) {
            constDef.parseAndAdd(NodeRegistry.TERMINAL);
            constDef.parseAndAdd(NodeRegistry.CONST_EXP);
            constDef.terminalCheck(LexType.RBRACK, ErrorType.k);
        }
        constDef.terminalCheck(LexType.ASSIGN);
        constDef.parseAndAdd(NodeRegistry.CONST_INIT_VAL);
        return constDef;
    }
}
