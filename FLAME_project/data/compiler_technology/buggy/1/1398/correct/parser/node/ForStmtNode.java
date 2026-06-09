package parser.node;

import lexer.Token;
import lexer.TokenType;
import parser.NodeType;

public class ForStmtNode {
    LValNode lValNode;
    Token assignTK;
    ExpNode expNode;
    public ForStmtNode(LValNode lValNode, Token assignTK, ExpNode expNode) {
        this.lValNode = lValNode;
        this.assignTK = assignTK;
        this.expNode = expNode;
    }
    public void print() {
        lValNode.print();
        assignTK.print();
        expNode.print();
        System.out.println(NodeType.ForStmt);
    }

}
