package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;
public class UnaryExpNode {
    public PrimaryExpNode primaryExpNode = null;
    public UnaryOpNode unaryOpNode = null;
    public UnaryExpNode unaryExpNode = null;
    public Token Ident = null;
    public Token leftParent = null;
    public Token rightParent = null;
    public FuncRParamsNode funcRParamsNode = null;
    public UnaryExpNode(PrimaryExpNode primaryExpNode){
        this.primaryExpNode = primaryExpNode;
    }
    public UnaryExpNode(UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode){
        this.unaryExpNode = unaryExpNode;
        this.unaryOpNode = unaryOpNode;
    }
    public UnaryExpNode(Token Ident, Token leftParent, Token rightParent, FuncRParamsNode funcRParamsNode){
        this.Ident = Ident;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.funcRParamsNode = funcRParamsNode;
    }
    public void print() throws IOException {
        if(unaryOpNode != null){
            unaryOpNode.print();
            unaryExpNode.print();
        }
        else if(primaryExpNode != null){
            primaryExpNode.print();
        }
        else {
            OutputUtils.parserOutput(leftParent.toString());
            if(funcRParamsNode != null){
                funcRParamsNode.print();
            }
            OutputUtils.parserOutput(rightParent.toString());
        }
        OutputUtils.parserOutput("<UnaryExp>\n");
    }
}
