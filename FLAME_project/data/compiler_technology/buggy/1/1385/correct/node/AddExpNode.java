package node;

import token.Token;
import java.io.IOException;
import java.util.ArrayList;

public class AddExpNode {
    // AddExp -> MulExp | AddExp ('+' | 'âˆ’') MulExp
    private ArrayList<MulExpNode> mulExpNodes;
    private ArrayList<Token> operators;

    public AddExpNode(ArrayList<MulExpNode> mulExpNodes,ArrayList<Token> operators) {
        this.mulExpNodes = mulExpNodes;
        this.operators = operators;
    }
    
    public void print() throws IOException {
        if (mulExpNodes.size()==1) {
            mulExpNodes.get(0).print();
            Io.Text.printWord("<AddExp>");
        }
        else {
            for (int i = 0;i<mulExpNodes.size()-1;i+=1) {
                mulExpNodes.get(i).print();
                Io.Text.printWord("<AddExp>");
                operators.get(i).print();
            }
            mulExpNodes.get(mulExpNodes.size()-1).print();
            Io.Text.printWord("<AddExp>");
        }
    }

}
