package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
// InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitValNode {
    private ExpNode expNode;
    private Token lbrace;
    private List<ExpNode> expNodes;
    private List<Token> commas;
    private Token rbrace;
    private Token strToken;
    public InitValNode(ExpNode expNode, Token lBrace, List<ExpNode> expNodes, Token rBrace, List<Token> commas, Token strConToken){
        this.expNode = expNode;
        this.lbrace = lBrace;
        this.expNodes = expNodes;
        this.commas = commas;
        this.rbrace = rBrace;
        this.strToken = strConToken;
    }
    public void print() {
        if (expNode != null) {
            expNode.print();
        } else if(strToken != null){
            strToken.print();
        } else{
            lbrace.print();
            if (!expNodes.isEmpty()) {
                expNodes.get(0).print();
                for (int i = 1; i < expNodes.size(); ++i){
                    commas.get(i-1).print();
                    expNodes.get(i).print();
                }
            }
            rbrace.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<InitVal>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
