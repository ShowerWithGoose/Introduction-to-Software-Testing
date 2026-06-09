package Node;
import Token.*;
import frontend.Parser;

import java.util.ArrayList;

public class RelExpNode {
    // RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    // RelExp -> AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    // RelExp -> AddExp | AddExp ('<' | '>' | '<=' | '>=') RelExp

//    private ArrayList<AddExpNode> addExpNodes;
//    private ArrayList<Token> ops;
//
//
//    public RelExpNode(ArrayList<AddExpNode> addExpNodes, ArrayList<Token> ops) {
//        this.addExpNodes = addExpNodes;
//        this.ops = ops;
//    }

    private AddExpNode addExpNode;
    private Token op;
    private RelExpNode relExpNode;
    public RelExpNode(AddExpNode addExpNode, Token op, RelExpNode relExpNode){
        this.addExpNode = addExpNode;
        this.op = op;
        this.relExpNode = relExpNode;
    }

    public void print(){
        addExpNode.print();
        Parser.getInstance().output(NodeType.RelExp);
        if(op != null){
            Parser.getInstance().output(op);
            relExpNode.print();
        }
    }

}
