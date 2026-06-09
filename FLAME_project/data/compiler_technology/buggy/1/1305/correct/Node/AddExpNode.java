package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class AddExpNode {
    public AddExpNode addExpNode;
    public MulExpNode mulExpNode;
    public Token op;
    public AddExpNode(MulExpNode mulExpNode, Token op, AddExpNode addExpNode){
        this.addExpNode = addExpNode;
        this.op = op;
        this.mulExpNode = mulExpNode;
    }
    public void print() throws IOException {
        mulExpNode.print();
        OutputUtils.parserOutput("<AddExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            addExpNode.print();
        }
    }
}
