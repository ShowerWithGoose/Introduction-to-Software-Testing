package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class ForStmtNode {
    //语句 ForStmt → LVal '=' Exp
    private LValNode lval;
    private Token assignToken;
    private ExpNode exp;

    public ForStmtNode(LValNode lval, Token assignToken, ExpNode exp) {
        this.lval = lval;
        this.assignToken = assignToken;
        this.exp = exp;
    }

    public void print() {
        lval.print();
        IO.ParserOutput(assignToken);
        exp.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.ForStmt));
    }
}
