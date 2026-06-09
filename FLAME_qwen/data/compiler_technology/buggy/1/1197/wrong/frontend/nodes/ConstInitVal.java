package frontend.nodes;

import frontend.*;

public class ConstInitVal extends Node {
    public ConstInitVal() {
        super(NodeType.CONST_INIT_VAL);
    }

    public static Node parse() {
        ConstInitVal constInitVal = new ConstInitVal();
        switch (Lexer.INSTANCE.getLexType()) {
            case LBRACE -> {
                constInitVal.parseAndAdd(NodeRegistry.TERMINAL);
                if (Lexer.INSTANCE.getLexType() != LexType.RBRACE) {
                    constInitVal.parseAndAdd(NodeRegistry.CONST_EXP);
                }
                while (Lexer.INSTANCE.getLexType() != LexType.RBRACE) {
                    constInitVal.terminalCheck(LexType.COMMA);
                    constInitVal.parseAndAdd(NodeRegistry.CONST_EXP);
                }
                constInitVal.terminalCheck(LexType.RBRACE);
            }
            case STRCON -> constInitVal.parseAndAdd(NodeRegistry.TERMINAL);
            default -> constInitVal.parseAndAdd(NodeRegistry.CONST_EXP);
        }
        return constInitVal;
    }
}
