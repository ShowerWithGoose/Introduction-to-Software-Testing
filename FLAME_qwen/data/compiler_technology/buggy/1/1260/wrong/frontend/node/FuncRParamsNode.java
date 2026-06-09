package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class FuncRParamsNode {
    private List<ExpNode> expNodes;
    private List<Token> commas;

    public FuncRParamsNode(List<ExpNode> expNodes, List<Token> commas) {
        this.expNodes = expNodes;
        this.commas = commas;
    }
    public void print() {
        expNodes.get(0).print();
        for (int i = 1; i < expNodes.size(); i++) {
            commas.get(i-1).print();
            expNodes.get(i).print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<FuncRParams>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
