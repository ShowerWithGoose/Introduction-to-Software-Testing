package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class FuncFParamNode {
    public BTypeNode bTypeNode;
    public Token Ident;
    public Token leftBracket;
    public Token rightBracket;
    public FuncFParamNode(BTypeNode bTypeNode, Token Ident, Token leftBracket, Token rightBracket){
        this.bTypeNode = bTypeNode;
        this.Ident = Ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }
    public void print() throws IOException {
        bTypeNode.print();
        OutputUtils.parserOutput(Ident.toString());
        if(leftBracket != null){
            OutputUtils.parserOutput(leftBracket.toString());
            OutputUtils.parserOutput(rightBracket.toString());
        }
        OutputUtils.parserOutput("<FuncFParam>\n");
    }
}
