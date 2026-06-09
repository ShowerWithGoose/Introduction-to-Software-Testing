package frontend.nodes;

import frontend.*;

public class VarDef extends Node {
    public VarDef() {
        super(NodeType.VAR_DEF);
    }

    public static Node parse() {
        VarDef varDef = new VarDef();
        varDef.terminalCheck(LexType.IDENFR);
        if (Lexer.INSTANCE.getLexType() == LexType.LBRACK) {
            varDef.parseAndAdd(NodeRegistry.TERMINAL);
            varDef.parseAndAdd(NodeRegistry.CONST_EXP);
            varDef.terminalCheck(LexType.RBRACK, ErrorType.k);
        }
        if (Lexer.INSTANCE.getLexType() == LexType.ASSIGN) {
            varDef.parseAndAdd(NodeRegistry.TERMINAL);
            varDef.parseAndAdd(NodeRegistry.INIT_VAL);
        }
        return varDef;
    }
}
