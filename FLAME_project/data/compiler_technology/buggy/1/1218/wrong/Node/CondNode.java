package Node;

import frontend.Parser;

public class CondNode {
    // Cond â†’ LOrExp
    private LOrExpNode lOrExpNode;
    public CondNode(LOrExpNode lOrExpNode){
        this.lOrExpNode = lOrExpNode;
    }

    public void print(){
        lOrExpNode.print();
        Parser.getInstance().output(NodeType.Cond);
    }
}
