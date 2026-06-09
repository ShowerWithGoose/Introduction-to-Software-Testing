package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class FuncFParamsNode {
    private List<FuncFParamNode> funcFParamNodes;
    private List<Token> commas;
    public FuncFParamsNode(List<Token> commas, List<FuncFParamNode> funcFParamNodes){
        this.funcFParamNodes = funcFParamNodes;
        this.commas = commas;
    }
    public void print() {
        funcFParamNodes.get(0).print();
        for (int i = 1; i < funcFParamNodes.size(); i++) {
            commas.get(i-1).print();
            funcFParamNodes.get(i).print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<FuncFParams>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
