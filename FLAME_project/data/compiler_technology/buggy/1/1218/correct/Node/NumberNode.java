package Node;
import Token.*;
import frontend.Parser;

public class NumberNode {
    //Number â†’ IntConst
    private Token intCon;
    public NumberNode(Token intCon){
        this.intCon = intCon;
    }

    public void print(){
        Parser.getInstance().output(intCon);
        Parser.getInstance().output(NodeType.Number);
    }
}
