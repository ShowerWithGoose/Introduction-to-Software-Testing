package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class ExpNode {
    public AddExpNode addExpNode;
    public ExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }
    public void print() throws IOException{
        addExpNode.print();
        OutputUtils.parserOutput("<Exp>\n");
    }
}
