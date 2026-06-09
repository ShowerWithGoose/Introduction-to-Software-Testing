package Node;
import Token.*;
import frontend.Parser;

public class UnaryOpNode {
    // UnaryOp → '+' | '−' | '!'
    private Token op;
    public UnaryOpNode(Token op){
        this.op = op;
    }

    public void print(){
        Parser.getInstance().output(op);
        Parser.getInstance().output(NodeType.UnaryOp);
    }
}
