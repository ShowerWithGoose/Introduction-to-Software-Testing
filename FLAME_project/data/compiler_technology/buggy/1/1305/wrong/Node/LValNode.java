package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class LValNode {
    public Token Ident;
    public Token leftBracket;
    public Token rightBracket;
    public ExpNode expNode;
    public LValNode(Token Ident, Token leftBracket, ExpNode expNode, Token rightBracket){
        this.Ident = Ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
        this.expNode = expNode;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(Ident.toString());
        if(leftBracket != null){
            OutputUtils.parserOutput(leftBracket.toString());
            expNode.print();
            OutputUtils.parserOutput(rightBracket.toString());
        }
        OutputUtils.parserOutput("<LVal>\n");
    }
}
