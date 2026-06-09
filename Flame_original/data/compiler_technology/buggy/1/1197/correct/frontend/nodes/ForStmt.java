package frontend.nodes;

import frontend.LexType;
import frontend.NodeRegistry;
import frontend.NodeType;

public class ForStmt extends Node {
    public ForStmt() {
        super(NodeType.FOR_STMT);
    }

    public static Node parse() {
        ForStmt forStmt = new ForStmt();
        forStmt.parseAndAdd(NodeRegistry.L_VAL);
        forStmt.terminalCheck(LexType.ASSIGN);
        forStmt.parseAndAdd(NodeRegistry.EXP);
        return forStmt;
    }
}
