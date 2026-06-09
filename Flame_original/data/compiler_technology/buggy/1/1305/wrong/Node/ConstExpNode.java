package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;

public class ConstExpNode {
    public AddExpNode addExpNode;
    public ConstExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }
    public void print() throws IOException {
        addExpNode.print();
        OutputUtils.parserOutput("<ConstExp>\n");
    }
}
