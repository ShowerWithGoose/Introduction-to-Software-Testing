package frontend.nodes;

import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class FuncType extends Node {
    public FuncType() {
        super(NodeType.FUNC_TYPE);
    }

    public static Node parse() {
        FuncType funcType = new FuncType();
        switch (Lexer.INSTANCE.getLexType()) {
            case VOIDTK, INTTK, CHARTK -> funcType.parseAndAdd(NodeRegistry.TERMINAL);
        }
        return funcType;
    }
}
