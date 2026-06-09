package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class AddExpNode {
    //AddExp → MulExp | AddExp ('+' | '−') MulExp
    //AddExp -> MulExp{ ('+' | '−') MulExp }
    //AddExp -> MulExp | MulExp ('+' | '−') AddExp

//    private ArrayList<MulExpNode> mulExpNodes;
//    private ArrayList<Token> ops;
//    public AddExpNode(ArrayList<MulExpNode> mulExpNodes, ArrayList<Token> ops) {
//        this.mulExpNodes = mulExpNodes;
//        this.ops = ops;
//    }
    private MulExpNode mulExpNode;
    private Token op;
    private AddExpNode addExpNode;
    public AddExpNode(MulExpNode mulExpNode, Token op, AddExpNode addExpNode){
        this.mulExpNode = mulExpNode;
        this.op = op;
        this.addExpNode = addExpNode;
    }

    public void print(){
        mulExpNode.print();
        Parser.getInstance().output(NodeType.AddExp);
        if(op != null){
            Parser.getInstance().output(op);
            addExpNode.print();
        }

    }
}
