package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;

public class ConstInitValNode {
    public ConstExpNode constExpNodeSingle = null;
    public List<ConstExpNode> constExpNodes = new ArrayList<>();
    public List<Token> commas;
    public Token leftBrace = null;
    public Token rightBrace = null;
    public Token stringConst = null;
    public ConstInitValNode(ConstExpNode constExpNodeSingle){
        this.constExpNodeSingle = constExpNodeSingle;
    }
    public ConstInitValNode(Token leftBrace, Token rightBrace, List<Token> commas, List<ConstExpNode> constExpNodes){
        this.constExpNodes = constExpNodes;
        this.commas = commas;
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }
    public ConstInitValNode(Token leftBrace, Token rightBrace){
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }
    public ConstInitValNode(Token stringConst){
        this.stringConst = stringConst;
    }
    public void print() throws IOException {
        if(stringConst != null){
            OutputUtils.parserOutput(stringConst.toString());
        }
        else if(leftBrace != null){
            OutputUtils.parserOutput(leftBrace.toString());
            if (!constExpNodes.isEmpty()){
                constExpNodes.get(0).print();
                for(int i = 1; i < constExpNodes.size(); i++) {
                    OutputUtils.parserOutput(commas.get(i - 1).toString());
                    constExpNodes.get(i).print();
                }
            }
            OutputUtils.parserOutput(rightBrace.toString());
        }
        else {
            constExpNodeSingle.print();
        }
        OutputUtils.parserOutput("<ConstInitVal>\n");
    }
}
