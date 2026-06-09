package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class EqExpNode {
    // RelExp | EqExp ('==' | '!=') RelExp
    private ArrayList<RelExpNode> relExpNodes;
    private ArrayList<Token> operators;

    public EqExpNode(ArrayList<RelExpNode> relExpNodes, ArrayList<Token> operators) {
        this.relExpNodes = relExpNodes;
        this.operators = operators;
    }
    
    public void print() throws IOException {
        if (operators.isEmpty()) {
            relExpNodes.get(0).print();
            Io.Text.printWord("<EqExp>");
        }
        else {
            for (int i = 0;i<relExpNodes.size()-1;i+=1) {
                relExpNodes.get(i).print();
                Io.Text.printWord("<EqExp>");
                operators.get(i).print();
            }
            relExpNodes.get(relExpNodes.size()-1).print();
            Io.Text.printWord("<EqExp>");
        }
    }
    
}
