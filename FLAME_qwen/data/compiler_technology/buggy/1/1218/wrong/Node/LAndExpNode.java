package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class LAndExpNode {
    // LAndExp â†’ EqExp | LAndExp '&&' EqExp
    // LAndExp -> EqExp { '&&' EqExp }
    // LAndExp -> EqExp | EqExp '&&' LAndExp

//    private ArrayList<EqExpNode> eqExpNodes;
//    private ArrayList<Token> andTokens;
//
//    public LAndExpNode(ArrayList<EqExpNode> eqExpNodes, ArrayList<Token> andTokens) {
//        this.eqExpNodes = eqExpNodes;
//        this.andTokens = andTokens;
//    }

    private EqExpNode eqExpNode;
    private Token op;
    private LAndExpNode lAndExpNode;
    public LAndExpNode(EqExpNode eqExpNode, Token op, LAndExpNode lAndExpNode){
        this.eqExpNode = eqExpNode;
        this.op = op;
        this.lAndExpNode = lAndExpNode;
    }

    public void print(){
        eqExpNode.print();
        Parser.getInstance().output(NodeType.LAndExp);
        if(op != null){
            Parser.getInstance().output(op);
            lAndExpNode.print();
        }
    }
}
