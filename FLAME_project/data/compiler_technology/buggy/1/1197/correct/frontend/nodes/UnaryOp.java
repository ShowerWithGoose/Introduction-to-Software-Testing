package frontend.nodes;

import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class UnaryOp extends Node {
    public UnaryOp() {
        super(NodeType.UNARY_OP);
    }

    public static Node parse() {
        UnaryOp unaryOp = new UnaryOp();
        switch (Lexer.INSTANCE.getLexType()) {
            case PLUS, MINU, NOT -> unaryOp.parseAndAdd(NodeRegistry.TERMINAL);
        }
        return unaryOp;
    }
}
