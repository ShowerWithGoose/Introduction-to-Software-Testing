package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class FuncRParamsNode {
    public List<ExpNode> expNodes = new ArrayList<>();
    public List<Token> commas = new ArrayList<>();
    public FuncRParamsNode(List<ExpNode> expNodes, List<Token> commas){
        this.expNodes = expNodes;
        this.commas = commas;
    }
    public void print() throws IOException {
        expNodes.get(0).print();
        for(int i = 1; i < expNodes.size(); i++){
            OutputUtils.parserOutput(commas.get(i-1).toString());
            expNodes.get(i).print();
        }
        OutputUtils.parserOutput("<FuncRParams>\n");
    }
}
