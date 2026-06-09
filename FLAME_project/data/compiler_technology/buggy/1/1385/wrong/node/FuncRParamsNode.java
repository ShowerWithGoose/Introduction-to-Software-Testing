package node;

import token.Token;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class FuncRParamsNode {
    // FuncRParams -> Exp { ',' Exp }

    private ArrayList<ExpNode> expNodes;
    private ArrayList<Token> commas;

    public FuncRParamsNode(ArrayList<ExpNode> expNodes, ArrayList<Token> commas) {
        this.expNodes = expNodes;
        this.commas = commas;
    }
    
    public void print() throws IOException {
        expNodes.get(0).print();
        if (!commas.isEmpty()) {
            for (int i=0;i<commas.size();i+=1){
                commas.get(i).print();
                expNodes.get(i+1).print();
            }
        }
        Io.Text.printWord("<FuncRParams>");
    }
}
