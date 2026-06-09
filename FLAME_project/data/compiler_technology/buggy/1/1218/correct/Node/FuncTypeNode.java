package Node;
import Token.*;
import frontend.Parser;

public class FuncTypeNode {
    //FuncType â†’ 'void' | 'int' | 'char'
    private Token type;
    public FuncTypeNode(Token type){
        this.type = type;
    }

    public void print(){
        Parser.getInstance().output(type);
        Parser.getInstance().output(NodeType.FuncType);
    }
}
