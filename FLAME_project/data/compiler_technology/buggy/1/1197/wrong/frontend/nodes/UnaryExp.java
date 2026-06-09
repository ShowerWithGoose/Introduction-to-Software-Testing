package frontend.nodes;

import frontend.*;

public class UnaryExp extends Node {
    public UnaryExp() {
        super(NodeType.UNARY_EXP);
    }

    public static Node parse() {
        UnaryExp unaryExp = new UnaryExp();
        switch (Lexer.INSTANCE.getLexType()) {
            case IDENFR -> {
                Lexer.INSTANCE.next();
                if (Lexer.INSTANCE.getLexType() == LexType.LPARENT) {
                    Lexer.INSTANCE.back();
                    unaryExp.parseAndAdd(NodeRegistry.TERMINAL);
                    unaryExp.terminalCheck(LexType.LPARENT);
                    if (Lexer.INSTANCE.getLexType() != LexType.RPARENT) {
                        unaryExp.parseAndAdd(NodeRegistry.FUNC_R_PARAMS);
                    }
                    unaryExp.terminalCheck(LexType.RPARENT, ErrorType.j);
                } else {
                    Lexer.INSTANCE.back();
                    unaryExp.parseAndAdd(NodeRegistry.PRIMARY_EXP);
                }
            }
            case PLUS, MINU, NOT -> {
                unaryExp.parseAndAdd(NodeRegistry.UNARY_OP);
                unaryExp.parseAndAdd(NodeRegistry.UNARY_EXP);
            }
            default -> unaryExp.parseAndAdd(NodeRegistry.PRIMARY_EXP);
        }
        return unaryExp;
    }
}
