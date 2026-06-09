package frontend.nodes;

import frontend.*;

public class PrimaryExp extends Node {
    public PrimaryExp() {
        super(NodeType.PRIMARY_EXP);
    }

    public static Node parse() {
        PrimaryExp primaryExp = new PrimaryExp();
        switch (Lexer.INSTANCE.getLexType()) {
            case LPARENT -> {
                primaryExp.parseAndAdd(NodeRegistry.TERMINAL);
                primaryExp.parseAndAdd(NodeRegistry.EXP);
                primaryExp.terminalCheck(LexType.RPARENT, ErrorType.j);
            }
            case CHRCON -> primaryExp.parseAndAdd(NodeRegistry.CHARACTER);
            case INTCON -> primaryExp.parseAndAdd(NodeRegistry.NUMBER);
            default -> primaryExp.parseAndAdd(NodeRegistry.L_VAL);
        }
        return primaryExp;
    }
}
