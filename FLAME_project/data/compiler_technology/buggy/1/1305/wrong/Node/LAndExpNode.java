package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class LAndExpNode {
    public EqExpNode eqExpNode;
    public LAndExpNode lAndExpNode;
    public Token op;
    public LAndExpNode(LAndExpNode lAndExpNode, Token op, EqExpNode eqExpNode){
        this.eqExpNode = eqExpNode;
        this.op = op;
        this.lAndExpNode = lAndExpNode;
    }
    public void print() throws IOException {
        eqExpNode.print();
        OutputUtils.parserOutput("<LAndExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            lAndExpNode.print();
        }
    }
}
