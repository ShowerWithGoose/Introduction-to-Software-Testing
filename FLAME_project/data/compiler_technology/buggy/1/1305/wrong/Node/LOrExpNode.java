package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class LOrExpNode {
    public LOrExpNode lOrExpNode;
    public LAndExpNode lAndExpNode;
    public Token op;
    public LOrExpNode(LAndExpNode lAndExpNode, Token op, LOrExpNode lOrExpNode){
        this.lOrExpNode = lOrExpNode;
        this.op = op;
        this.lAndExpNode = lAndExpNode;
    }
    public void print() throws IOException {
        lAndExpNode.print();
        OutputUtils.parserOutput("<LOrExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            lOrExpNode.print();
        }
    }
}
