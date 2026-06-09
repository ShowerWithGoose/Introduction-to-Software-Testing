package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class VarDefNode {
    public Token Ident;
    public Token leftBracket;
    public Token rightBracket;
    public Token equal;
    public InitValNode initValNode;
    public ConstExpNode constExpNode;
    public VarDefNode(Token Ident, Token leftBracket, Token rightBracket, Token equal, ConstExpNode constExpNode, InitValNode initValNode){
        this.constExpNode = constExpNode;
        this.initValNode = initValNode;
        this.equal = equal;
        this.Ident = Ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(Ident.toString());
        if(leftBracket != null){
            OutputUtils.parserOutput(leftBracket.toString());
            constExpNode.print();
            OutputUtils.parserOutput(rightBracket.toString());
        }
        if(equal != null){
            OutputUtils.parserOutput(equal.toString());
            initValNode.print();
        }
        OutputUtils.parserOutput("<VarDef>\n");
    }
}
