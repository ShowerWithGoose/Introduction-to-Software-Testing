package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:18
 */
public class ForStmtNode {
    // ForStmt → LVal '=' Exp
    LvalNode lvalNode;
    token assign;
    ExpNode expNode;
    public ForStmtNode(LvalNode lvalNode,token assign,ExpNode expNode){
        this.lvalNode=lvalNode;
        this.assign=assign;
        this.expNode=expNode;
    }

    public void output() throws IOException {
        lvalNode.output();
        out.write(assign.toString());
        expNode.output();
        out.write("<ForStmt>");
    }
}
