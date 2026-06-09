package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class InitVal extends Node {
    public InitVal() {
        super(NodeType.INIT_VAL);
    }

    public static Node parse() {
        InitVal initVal = new InitVal();
        switch (Lexer.INSTANCE.getLexType()) {
            case STRCON -> initVal.parseAndAdd(NodeRegistry.TERMINAL);
            case LBRACE -> {
                initVal.parseAndAdd(NodeRegistry.TERMINAL);
                if (Lexer.INSTANCE.getLexType() != LexType.RBRACE) {
                    initVal.parseAndAdd(NodeRegistry.EXP);
                }
                while (Lexer.INSTANCE.getLexType() != LexType.RBRACE) {
                    initVal.terminalCheck(LexType.COMMA);
                    initVal.parseAndAdd(NodeRegistry.EXP);
                }
                initVal.terminalCheck(LexType.RBRACE);
            }
            default -> initVal.parseAndAdd(NodeRegistry.EXP);
        }
        return initVal;
    }
}
