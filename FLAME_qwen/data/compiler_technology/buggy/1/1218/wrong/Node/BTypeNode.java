package Node;
import Token.*;
import frontend.Parser;

public class BTypeNode {
    //BType â†’ 'int' | 'char'
    private Token type;
    public BTypeNode(Token type){
        this.type = type;
    }

    public void print(){
        Parser.getInstance().output(type);
    }
}
