package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class UnaryOpNode {
    public Token unaryOp;
    public UnaryOpNode(Token unaryOp){
        this.unaryOp = unaryOp;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(unaryOp.toString());
        OutputUtils.parserOutput("<UnaryOp>\n");
    }
}
