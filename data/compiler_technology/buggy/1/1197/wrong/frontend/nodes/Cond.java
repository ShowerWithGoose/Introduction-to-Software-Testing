package frontend.nodes;

import frontend.NodeRegistry;
import frontend.NodeType;

public class Cond extends Node {
    public Cond() {
        super(NodeType.COND);
    }

    public static Node parse() {
        Cond cond = new Cond();
        cond.parseAndAdd(NodeRegistry.L_OR_EXP);
        return cond;
    }
}
