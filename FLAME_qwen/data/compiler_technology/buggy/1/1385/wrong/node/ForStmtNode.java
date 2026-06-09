package node;

import token.Token;

import java.io.IOException;

public class ForStmtNode {
    // ForStmt â†’ LVal '=' Exp
    private LValNode lValNode;
    private Token assignToken;
    private ExpNode expNode;
    
    public ForStmtNode(LValNode lValNode,Token assignToken,ExpNode expNode) {
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.expNode = expNode;
    }
    
    public void print() throws IOException {
        lValNode.print();
        assignToken.print();
        expNode.print();
        Io.Text.printWord("<ForStmt>");
    }
}
