package frontend.nodes;

import frontend.*;

public class VarDecl extends Node {
    public VarDecl() {
        super(NodeType.VAR_DECL);
    }

    public static Node parse() {
        VarDecl varDecl = new VarDecl();
        varDecl.parseAndAdd(NodeRegistry.B_TYPE);
        varDecl.parseAndAdd(NodeRegistry.VAR_DEF);
        while (Lexer.INSTANCE.getLexType() == LexType.COMMA) {
            varDecl.parseAndAdd(NodeRegistry.TERMINAL);
            varDecl.parseAndAdd(NodeRegistry.VAR_DEF);
        }
        varDecl.terminalCheck(LexType.SEMICN, ErrorType.i);
        return varDecl;
    }
}
