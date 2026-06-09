package node;


import token.Token;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class FuncFParamsNode {
    // FuncFParams -> FuncFParam { ',' FuncFParam }

    private ArrayList<FuncFParamNode> funcFParamNodes;
    private ArrayList<Token> commas;

    public FuncFParamsNode(ArrayList<FuncFParamNode> funcFParamNodes, ArrayList<Token> commas) {
        this.funcFParamNodes = funcFParamNodes;
        this.commas = commas;
    }
    
    public void print() throws IOException {
        funcFParamNodes.get(0).print();
        if (!commas.isEmpty()) {
            for (int i=0;i<commas.size();i+=1){
                commas.get(i).print();
                funcFParamNodes.get(i+1).print();
            }
        }
        Io.Text.printWord("<FuncFParams>");
    }
}
