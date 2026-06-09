package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class EqExpNode {
    public EqExpNode eqExpNode;
    public RelExpNode relExpNode;
    public Token op;
    public EqExpNode(RelExpNode relExpNode, Token op, EqExpNode eqExpNode){
        this.eqExpNode = eqExpNode;
        this.op = op;
        this.relExpNode = relExpNode;
    }
    public void print() throws IOException {
        relExpNode.print();
        OutputUtils.parserOutput("<EqExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            eqExpNode.print();
        }
    }
}
