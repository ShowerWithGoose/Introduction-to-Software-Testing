package Node;

import frontend.Parser;
import Token.*;
public class ForStmtNode {
    // ForStmt â†’ LVal '=' Exp
    private LValNode lValNode;
    private ExpNode expNode;
    Token eqToken;
    public ForStmtNode(LValNode lValNode, ExpNode expNode, Token eqToken){
        this.lValNode = lValNode;
        this.expNode = expNode;
        this.eqToken = eqToken;
    }

    public void print(){
        lValNode.print();
        Parser.getInstance().output(eqToken);
        expNode.print();
        Parser.getInstance().output(NodeType.ForStmt);
    }
}
