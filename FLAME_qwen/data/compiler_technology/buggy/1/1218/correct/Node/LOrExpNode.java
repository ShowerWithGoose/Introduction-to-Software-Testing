package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class LOrExpNode {
    // LOrExp â†’ LAndExp | LOrExp '||' LAndExp
    // LOrExp -> LAndExp { '||' LAndExp }
    // LOrExp -> LAndExp | LAndExp '||' LOrExp

//    private ArrayList<LAndExpNode> lAndExpNodes;
//    private ArrayList<Token> orTokens;
//
//    public LOrExpNode(ArrayList<LAndExpNode> lAndExpNodes, ArrayList<Token> orTokens) {
//        this.lAndExpNodes = lAndExpNodes;
//        this.orTokens = orTokens;
//    }
    private LAndExpNode lAndExpNode;
    private Token op;
    private LOrExpNode lOrExpNode;
    public LOrExpNode(LAndExpNode lAndExpNode, Token op, LOrExpNode lOrExpNode){
        this.lAndExpNode = lAndExpNode;
        this.op = op;
        this.lOrExpNode = lOrExpNode;
    }

    public void print(){
        lAndExpNode.print();
        Parser.getInstance().output(NodeType.LOrExp);
        if(op != null){
            Parser.getInstance().output(op);
            lOrExpNode.print();
        }
    }
}
