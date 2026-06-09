package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class InitValNode {
    public ExpNode expNodeSingle;
    public List<ExpNode> expNodes = new ArrayList<>();
    public List<Token> commas;
    public Token leftBrace;
    public Token rightBrace;
    public Token stringConst;
    public InitValNode(ExpNode expNodeSingle){
        this.expNodeSingle = expNodeSingle;
    }
    public InitValNode(Token leftBrace, Token rightBrace, List<Token> commas, List<ExpNode> expNodes){
        this.expNodes = expNodes;
        this.commas = commas;
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }
    public InitValNode(Token leftBrace, Token rightBrace){
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }
    public InitValNode(Token stringConst){
        this.stringConst = stringConst;
    }
    public void print() throws IOException {
        if(stringConst != null){
            OutputUtils.parserOutput(stringConst.toString());
        }
        else if(leftBrace != null){
            OutputUtils.parserOutput(leftBrace.toString());
            if (!expNodes.isEmpty()){
                expNodes.get(0).print();
                for(int i = 1; i < expNodes.size(); i++) {
                    OutputUtils.parserOutput(commas.get(i - 1).toString());
                    expNodes.get(i).print();
                }
            }
            OutputUtils.parserOutput(rightBrace.toString());
        }
        else {
            expNodeSingle.print();
        }
        OutputUtils.parserOutput("<InitVal>\n");
    }
}
