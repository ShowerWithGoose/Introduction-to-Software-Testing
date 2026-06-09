package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class LAndExpNode {
    // LAndExp -> EqExp | LAndExp '&&' EqExp
    private ArrayList<EqExpNode> eqExpNodes;
    private ArrayList<Token> andTokens;

    public LAndExpNode(ArrayList<EqExpNode> eqExpNodes, ArrayList<Token> andTokens) {
        this.eqExpNodes = eqExpNodes;
        this.andTokens = andTokens;
    }
    
    public void print() throws IOException {
        if (andTokens.isEmpty()) {
            eqExpNodes.get(0).print();
            Io.Text.printWord("<LAndExp>");
        }
        else {
            for (int i = 0;i<eqExpNodes.size()-1;i+=1) {
                eqExpNodes.get(i).print();
                Io.Text.printWord("<LAndExp>");
                andTokens.get(i).print();
            }
            eqExpNodes.get(eqExpNodes.size()-1).print();
            Io.Text.printWord("<LAndExp>");
        }
    }
}
