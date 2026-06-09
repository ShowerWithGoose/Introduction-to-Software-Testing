package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class CondNode {
    public LOrExpNode lOrExpNode;
    public CondNode(LOrExpNode lOrExpNode){
        this.lOrExpNode = lOrExpNode;
    }
    public void print() throws IOException {
        lOrExpNode.print();
        OutputUtils.parserOutput("<Cond>\n");
    }
}
