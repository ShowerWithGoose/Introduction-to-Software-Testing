package frontend.nodes;

import frontend.LexType;
import frontend.NodeType;

public class Number extends Node {
    public Number() {
        super(NodeType.NUMBER);
    }

    public static Node parse() {
        Number number = new Number();
        number.terminalCheck(LexType.INTCON);
        return number;
    }
}
