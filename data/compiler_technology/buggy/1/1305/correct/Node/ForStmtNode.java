package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class ForStmtNode {
    public LValNode lValNode;
    public ExpNode expNode;
    public Token equal;
    public ForStmtNode(LValNode lValNode, ExpNode expNode, Token equal){
        this.expNode = expNode;
        this.lValNode = lValNode;
        this.equal = equal;
    }
    public void print() throws IOException {
        lValNode.print();
        OutputUtils.parserOutput(equal.toString());
        expNode.print();
        OutputUtils.parserOutput("<ForStmt>\n");
    }
}
