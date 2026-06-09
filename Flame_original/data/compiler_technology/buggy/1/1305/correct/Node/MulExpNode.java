package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class MulExpNode {
    public MulExpNode mulExpNode;
    public UnaryExpNode unaryExpNode;
    public Token op;
    public MulExpNode(MulExpNode mulExpNode, Token op, UnaryExpNode unaryExpNode){
        this.unaryExpNode = unaryExpNode;
        this.op = op;
        this.mulExpNode = mulExpNode;
    }
    public void print() throws IOException {
        unaryExpNode.print();
        OutputUtils.parserOutput("<MulExp>\n");
        if(op != null){
            OutputUtils.parserOutput(op.toString());
            mulExpNode.print();
        }
    }
}
