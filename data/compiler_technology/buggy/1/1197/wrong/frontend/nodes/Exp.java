package frontend.nodes;

import frontend.NodeRegistry;
import frontend.NodeType;

public class Exp extends Node {
    public Exp() {
        super(NodeType.EXP);
    }

    public static Node parse() {
        Exp exp = new Exp();
        exp.parseAndAdd(NodeRegistry.ADD_EXP);
        return exp;
    }
}
