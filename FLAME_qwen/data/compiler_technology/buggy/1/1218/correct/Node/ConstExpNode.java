package Node;

import frontend.Parser;

public class ConstExpNode {
    //ConstExp â†’ AddExp
    private AddExpNode addExpNode;
    public ConstExpNode(AddExpNode addExpNode){
        this.addExpNode = addExpNode;
    }

    public void print(){
        addExpNode.print();
        Parser.getInstance().output(NodeType.ConstExp);
    }
}
