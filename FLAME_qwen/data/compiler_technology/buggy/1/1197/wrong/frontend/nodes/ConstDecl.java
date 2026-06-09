package frontend.nodes;

import frontend.*;

public class ConstDecl extends Node {
    public ConstDecl() {
        super(NodeType.CONST_DECL);
    }

    public static Node parse() {
        ConstDecl constDecl = new ConstDecl();
        constDecl.terminalCheck(LexType.CONSTTK);
        constDecl.parseAndAdd(NodeRegistry.B_TYPE);
        constDecl.parseAndAdd(NodeRegistry.CONST_DEF);
        while (Lexer.INSTANCE.getLexType() == LexType.COMMA) {
            constDecl.parseAndAdd(NodeRegistry.TERMINAL);
            constDecl.parseAndAdd(NodeRegistry.CONST_DEF);
        }
        constDecl.terminalCheck(LexType.SEMICN, ErrorType.i);
        return constDecl;
    }
}
