package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class FuncFParamsNode {
    public List<FuncFParamNode> funcFParamNodes = new ArrayList<>();
    public List<Token> commas = new ArrayList<>();
    public FuncFParamsNode(List<FuncFParamNode> funcFParamNodes, List<Token> commas){
        this.commas = commas;
        this.funcFParamNodes = funcFParamNodes;
    }
    public void print() throws IOException {
        funcFParamNodes.get(0).print();
        for(int i = 1; i < funcFParamNodes.size(); i++){
            OutputUtils.parserOutput(commas.get(i-1).toString());
            funcFParamNodes.get(i).print();
        }
        OutputUtils.parserOutput("<FuncFParams>\n");
    }
}
