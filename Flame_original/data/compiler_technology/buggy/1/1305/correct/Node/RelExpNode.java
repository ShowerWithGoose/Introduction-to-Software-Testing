package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class RelExpNode {
    public AddExpNode addExpNode;
    public RelExpNode relExpNode;
    public Token op;
    public RelExpNode(RelExpNode relExpNode, Token op, AddExpNode addExpNode){
        this.addExpNode = addExpNode;
        this.op = op;
        this.relExpNode = relExpNode;
    }
    public void print() throws IOException {
        addExpNode.print();
        OutputUtils.parserOutput("<RelExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            relExpNode.print();
        }
    }
}
