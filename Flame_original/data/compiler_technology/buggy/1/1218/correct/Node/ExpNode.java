package Node;

import frontend.Parser;

public class ExpNode {
    // Exp â†’ AddExp
    private AddExpNode addExpNode;
    public ExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }

    public void print(){
        addExpNode.print();
        Parser.getInstance().output(NodeType.Exp);
    }
}
