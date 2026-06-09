package frontend.nodes;

import frontend.NodeRegistry;
import frontend.NodeType;

public class ConstExp extends Node {
    public ConstExp() {
        super(NodeType.CONST_EXP);
    }

    public static Node parse() {
        ConstExp constExp = new ConstExp();
        constExp.parseAndAdd(NodeRegistry.ADD_EXP);
        return constExp;
    }
}
