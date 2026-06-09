package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class EqExpNode {
    // EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
    // EqExp -> RelExp { ('==' | '!=') RelExp }
    // EqExp -> RelExp | RelExp ('==' | '!=') EqExp

//    private ArrayList<RelExpNode> relExpNodes;
//    private ArrayList<Token> ops;
//
//    public EqExpNode(ArrayList<RelExpNode> relExpNodes, ArrayList<Token> ops) {
//        this.relExpNodes = relExpNodes;
//        this.ops = ops;
//    }

    private RelExpNode relExpNode;
    private Token op;
    private EqExpNode eqExpNode;
    public EqExpNode(RelExpNode relExpNode, Token op, EqExpNode eqExpNode){
        this.relExpNode = relExpNode;
        this.op = op;
        this.eqExpNode = eqExpNode;
    }

    public void print(){
        relExpNode.print();
        Parser.getInstance().output(NodeType.EqExp);
        if(op != null){
            Parser.getInstance().output(op);
            eqExpNode.print();
        }
    }
}
