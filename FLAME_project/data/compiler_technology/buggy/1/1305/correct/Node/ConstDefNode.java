package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class ConstDefNode {
    public Token Ident;
    public Token leftBracket = null;
    public Token rightBracket;
    public Token equal;
    public ConstInitValNode constInitValNode;
    public ConstExpNode constExpNode;
    public ConstDefNode(Token Ident, Token leftBracket, Token rightBracket, Token equal, ConstExpNode constExpNode, ConstInitValNode constInitValNode){
        this.constExpNode = constExpNode;
        this.constInitValNode = constInitValNode;
        this.equal = equal;
        this.Ident = Ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }
    public ConstDefNode(Token Ident, Token equal, ConstInitValNode constInitValNode){
        this.constInitValNode = constInitValNode;
        this.equal = equal;
        this.Ident = Ident;
    }
    public void print() throws IOException {
        OutputUtils.parserOutput(Ident.toString());
        if(leftBracket != null){
            OutputUtils.parserOutput(leftBracket.toString());
            constExpNode.print();
            OutputUtils.parserOutput(rightBracket.toString());
        }
        OutputUtils.parserOutput(equal.toString());
        constInitValNode.print();
        OutputUtils.parserOutput("<ConstDef>\n");
    }
}
