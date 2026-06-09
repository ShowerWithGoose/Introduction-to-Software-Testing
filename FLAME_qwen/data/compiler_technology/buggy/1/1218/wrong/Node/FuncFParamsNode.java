package Node;

import java.util.ArrayList;
import Token.*;
import frontend.Parser;

public class FuncFParamsNode {
    // FuncFParams â†’ FuncFParam { ',' FuncFParam }
    private ArrayList<FuncFParamNode> funcParamNodes;
    ArrayList<Token> commas;
    public FuncFParamsNode(ArrayList<FuncFParamNode> funcParamNodes, ArrayList<Token> commas){
        this.commas = commas;
        this.funcParamNodes = funcParamNodes;
    }

    public void print(){
        funcParamNodes.get(0).print();
        for(int i = 1; i < funcParamNodes.size(); i++){
            Parser.getInstance().output(commas.get(i - 1));
            funcParamNodes.get(i).print();
        }
        Parser.getInstance().output(NodeType.FuncFParams);
    }
}
