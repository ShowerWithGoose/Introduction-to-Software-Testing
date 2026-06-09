package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class LOrExpNode {
    // LOrExp -> LAndExp | LOrExp '||' LAndExp
    private ArrayList<LAndExpNode> lAndExpNodes;
    private ArrayList<Token> orTokens;

    public LOrExpNode(ArrayList<LAndExpNode> lAndExpNodes, ArrayList<Token> orTokens) {
        this.lAndExpNodes = lAndExpNodes;
        this.orTokens = orTokens;
    }
    
    public void print() throws IOException {
        if (orTokens.isEmpty()) {
            lAndExpNodes.get(0).print();
            Io.Text.printWord("<LOrExp>");
        }
        else {
            for (int i = 0;i<lAndExpNodes.size()-1;i+=1) {
                lAndExpNodes.get(i).print();
                Io.Text.printWord("<LOrExp>");
                orTokens.get(i).print();
            }
            lAndExpNodes.get(lAndExpNodes.size()-1).print();
            Io.Text.printWord("<LOrExp>");
        }
    }
}
