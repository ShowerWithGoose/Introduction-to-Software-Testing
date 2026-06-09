package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class MulExpNode {
    //MulExp â†’ UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    //MulExp -> UnaryExp { ('*' | '/' | '%') UnaryExp }
    //MulExp -> UnaryExp | UnaryExp ('*' | '/' | '%') MulExp

//    private ArrayList<UnaryExpNode> unaryExpNodes;
//    private ArrayList<Token> ops;
//    public MulExpNode(ArrayList<UnaryExpNode> unaryExpNodes, ArrayList<Token> ops) {
//        this.unaryExpNodes = unaryExpNodes;
//        this.ops = ops;
//    }

    private UnaryExpNode unaryExpNode;
    private Token op;
    private MulExpNode mulExpNode;
    public MulExpNode(UnaryExpNode unaryExpNode, Token op, MulExpNode mulExpNode){
        this.unaryExpNode = unaryExpNode;
        this.op = op;
        this.mulExpNode = mulExpNode;
    }

    public void print(){
        unaryExpNode.print();
        Parser.getInstance().output(NodeType.MulExp);
        if(op != null){
            Parser.getInstance().output(op);
            mulExpNode.print();
        }
    }
}
