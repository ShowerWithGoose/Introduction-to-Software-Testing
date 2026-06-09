package Node;

import java.util.ArrayList;
import Token.*;
import frontend.Parser;

public class FuncRParamsNode {
    // FuncRParams â†’ Exp { ',' Exp }
    private ArrayList<ExpNode> expNodes;
    ArrayList<Token> commas;
    public FuncRParamsNode(ArrayList<ExpNode> expNodes, ArrayList<Token> commas){
        this.commas = commas;
        this.expNodes = expNodes;
    }

    public void print(){
        expNodes.get(0).print();
        for(int i = 1; i < expNodes.size(); i++){
            Parser.getInstance().output(commas.get(i - 1));
            expNodes.get(i).print();
        }
        Parser.getInstance().output(NodeType.FuncRParams);
    }
}
