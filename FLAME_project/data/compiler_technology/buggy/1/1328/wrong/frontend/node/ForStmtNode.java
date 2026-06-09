package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class ForStmtNode {
    // 语句 ForStmt → LVal '=' Exp

    private LValNode lValNode;
    private Token assignToken;
    private ExpNode expNode;

    public ForStmtNode(LValNode lValNode, Token assignToken, ExpNode expNode) {
        // LVal '=' Exp
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.expNode = expNode;
    }

    public LValNode getlValNode() {
        return lValNode;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public void print() {
        lValNode.print();
        MyIO.writeToken(assignToken.toString());
        expNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.ForStmt));
    }
}
